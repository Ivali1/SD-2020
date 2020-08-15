#include<iostream>
#include "List.h"
#include <string>

int add(int first, int second)
{
	return first + second;
}

//i cannot do that. Please advise for this one
void sub(int data)
{
	;

}

int mul(int first, int second)
{
	return first*second;
}

double div(int first, int second)
{

	if (second == 0)
	{
		exit(1);
	}
	double result=first / second;
	return result;
}

int pow(int data, int step)
{
	while (step != 0)
	{
		data = data*data;
		--step;
 }
}
int sqrt(int data)
{
	while (data % 2 == 0)
	{
		data = data / 2;
	}
	return data;
}

// here is missing  something how reversed to sin
int sin(int data)
{
	//Value representing an angle expressed in radians.
	//	One radian is equivalent to 180 / PI degrees.
	return data*3.14159265 / 180;
}

// here is missing  something how reversed to cos

int cos(int data)
{
	//Value representing an angle expressed in radians.
	//	One radian is equivalent to 180 / PI degrees.
	return data*3.14159265 / 180;

}
bool eq(int first, int second)
{
	if (first = second)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool nand(int first, int second)
{
	if (first == second)
	{
		return false;
	}
	/* ttps://www.rfwireless-world.com/Terminology/AND-vs-NAND-vs-OR-vs-NOR.html */

	else
	{
		return true;
	}
}

//le. Please advise what means le.I have no idea what has to do this function.


int ifFunc(int first, int second, int third) {
	if (first == 0)
	{
		return third;
	}
	else
	{
		return second;
	}
}
int list(int* numbers, int n)
{
	LinkedList<int> result;
	for (int i = 0; i < n; ++i)
	{
		result.pushBack(numbers[i]);
	}
}

int head(LinkedList<int> list)
{
	return list.getFirst();
}
LinkedList<int>* tail(LinkedList<int>* list)
{
	LinkedList<int>* result;
	LinkedList<int>* temp = list;
	list->popFront();
	for (int i = 0; i < temp->getSize(); ++i)
	{
		result->pushBack(temp[i].getFirst());
	}

	return result;
}

LinkedList<int>* concat(LinkedList<int>* first, LinkedList<int>* second)
{
	LinkedList<int>* result = first;
	while (result != NULL)
	{
		result->iterator();
	}
	LinkedList<int>* temp = second;
	while (second != NULL)
	{
		result->pushBack(second->getFirst());
		result->iterator();
		second->iterator();
	}

	return result;
}

//Функцията map, която приема 2 аргумента <function-name>, <list>. 
//Резултатът от тази функция с списък с брой елементи колкото елементи има в подадения списък (втория аргумент), 
//и стойността на всеки елемент е резултата от оценяването на подадената функция върху стойността от входния списък.
//ttps://www.youtube.com/watch?v=67vTjgbT56Q

int main()
{
	std::string function;
	std::cout << "Enter fuction: ";
	std::getline(std::cin, function);
	int i = 0;
	char* FunctionName;
	// We will hava a problem when there is a function in a function. Please see the example: add(add(3, 5), add(10, 10))
// May be we have to put the expretion in a stek. One stek for function names, one for brackets and one for numbers but i do not sure
	//  how to make that. Please advise.
	while (i < function.length() && function[i] != '(')
	{
		FunctionName[i] = function[i];
	}
	if (strcmp(FunctionName, "add")==0)
	{
		;
	}
	else if (strcmp(FunctionName, "sub") == 0)
	{

	}
	else if (strcmp(FunctionName, "mul") == 0)
	{

	}
	else if (strcmp(FunctionName, "div") == 0)
	{

	}
	else if (strcmp(FunctionName, "sin") == 0)
	{

	}
	else if (strcmp(FunctionName, "cos") == 0)
	{

	}
	else if (strcmp(FunctionName, "pow") == 0)
	{

	}
	else if (strcmp(FunctionName, "sqrt") == 0)
	{

	}
	else if (strcmp(FunctionName, "eq") == 0)
	{


	}
	else if (strcmp(FunctionName, "nand") == 0)
	{

	}
	else if (strcmp(FunctionName, "	if") == 0)
	{

	}
	else if (strcmp(FunctionName, "	list") == 0)
	{

	}
	else if (strcmp(FunctionName, "head") == 0)
	{

	}
	else if (strcmp(FunctionName, "tail") == 0)
	{

	}
	else if (strcmp(FunctionName, "concat") == 0)
	{

	}
	else if (strcmp(FunctionName, "map") == 0)
	{

	}
	return 0;
}