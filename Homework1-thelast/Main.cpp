#include <iostream>
#include<string>
#include <sstream>
#include <algorithm>


struct Data
{
	std::string str;
	Data* next;
	Data()
	{
		str ="";
		next = NULL;
	}

};

void print(Data* root)
{
	Data* current = root;
	do
	{
		std::cout<<"->"<<current->str;
		current = current->next;
	} while (current != root);
}

Data* addToList(Data* root,std::string str)
{
	Data* temp=NULL;

	if (root->str.length() == 0)
	{
		temp=root;
		temp->str = str;
		// we make it to point to itself
		temp->next = root;
	}
	else
	{
		Data* current = root;
		temp = new Data;
		//we move forward while the root is equal to the first element
		while(root->next!= current)
		{
			root = root->next;
		}
		// pint the last element to temp
       root->next = temp;
	   temp->str = str;
	   // temp point to the first element
	   temp->next = current;

   return temp;

	}

}
Data* removeNode(Data* root)
{
	if(root == NULL)
	{
		throw "The list is empty";
	}
	
			Data* temp = root;
			root = root->next;
			Data* current = root;
			 // we move forward without the element which we want to delete
			while (current->next != temp)
			{
				current = current->next;
			}
			current->next = root;
			delete temp;

			return root;		
	


}
//The  program do not work in the case that letter in the beginning is upper so mine example is only with low letters.
Data*  concate(Data* root)
{
	Data* iter = root;

	while(iter->next!= root)
	{
		iter = iter->next;
	}
	//last element in the list
	Data* current = iter;
	//first element in the list
	Data* next = iter->next;
	Data* temp = new Data;
	std::string result;
	bool flag = false;


	while (next!=iter)
	{// compare the first letter on the current root with the last letter on the next root
		if(current->str.substr(current->str.length()-1) == next->str.substr(0, 1))
		{
			result = "";
			flag = false;
			// compare the first letter on the current root with the last letter on the next root while next is differen to the last ementent in the list
			while (current->str.substr(current->str.length()-1) == next->str.substr(0, 1) && next != iter)
			{
				//concatanete the word with the same letter
				if (flag == false)
				{
					result = result.append(current->str);
					result = result.append("-");
					result = result.append(next->str);
					flag = true;
				}
				else
				{
					result = result.append("-");
					result = result.append(next->str);

				}
				current = current->next;
				next = next->next;
				
			}
			//add in the new list
			addToList(temp, result);

		}
		else
		{
			//add in the new list the single words
				result = "";
				result = result.append(next->str);
				addToList(temp, result);
			    current = current->next;
			    next = next->next;
			
		   // if the first letter on the current root is he same as the last letter on the next root and next is differen to the last ementent in the list, just 
		   // we move forwerd current and next
			if ((current->str.substr(current->str.length() - 1) != next->str.substr(0, 1)) && next !=  iter)
			{
				current = current->next;
				next = next->next;
			
		     }

		}
		
	
	}
	return temp;

}

int letList(Data* root)
{
	int len = 0;
	Data* current = root;
	do
	{
		current = current->next;
		++len;
	} while (current != root);

	return len;
}

std::string getLongestPath(Data* root)
{
	Data* temp = root;
	std::string result ="";
	int maxLen = 0;
		do
		{     //if temp's length is bigger than maxLen swap the lenghts and find new max path
			if (temp->str.length()>=maxLen)
			{
				result = "";
				maxLen = temp->str.length();
				result= temp->str;
			}

			temp = temp->next;

		} while (temp!= root);

		return result;
}

Data* getShortestNode(Data* root)
{
	Data* temp = root;

	// it will contain the shortest node
	Data* found = NULL;
	int minLen = -1;
	do
	{
		//if temp's legnth is smaller that min len
		if (temp->str.length() > 0 && (temp->str.length() <= minLen))
		{
			// swap the lengths and find new min path
			minLen = temp->str.length();
			found = temp;
		}
		temp = temp->next;
	} while (temp != root);
	return found;
}
Data* Sort(Data* root)
{
	Data* start=NULL;
	Data* temp = root;
	Data* first = root;
	Data* result= new Data;
	Data* next = NULL;
	//lenght of the list
	int len = letList(temp);
	while (len >=1)
	{
		// find the sorthers path
		start = getShortestNode(temp);
		// add in the new list which contains the sorted list
		addToList(result, start->str);
		//delete the shortest node from the list
		temp = removeNode(start);
		--len;
	}
	 

	return result;
}

int main()
{
	std::string strings[8] = {"street", "taxi","ink","dog","smile","eat","tall","pass" };

	std::cout << "Input:"<<std::endl;
	for (int i = 0; i <8; ++i)
	{
		std::cout << strings[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	Data* root = new Data;
	for (int i = 0; i <8; ++i)
	{
		addToList(root, strings[i]);
	}
	std::cout << "Output:"<<std::endl;
     root = concate(root);
	// print(root);
	
	root = Sort(root);
	print(root);
	std::cout << std::endl;

	std::cout << "Longest: ";
	std::cout<<getLongestPath(root);
	std::cout << std::endl;



	return 0;
}
