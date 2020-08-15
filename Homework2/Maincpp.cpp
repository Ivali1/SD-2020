#include<iostream>
#include <fstream>

struct NodeBT
{
	int data;
	NodeBT* left;
	NodeBT* right;

	NodeBT(int otherData)
	{
		data = otherData;
		left = right = NULL;
	}
	NodeBT()
	{
		left = NULL;
		right = NULL;
	}
};

/*void Load(std::ifstream file)
{

	file.open("tree.txt");
	char bracket;
	int rootData;
	int  rootLeftData;
	int  rootRightData;
	if (!file.is_open())
	{
		std::cerr << "The file cannot be open";
		abort();
	}
	while (file >>bracket >> rootData>> bracket>>rootLeftData>>bracket>>rootRightData)
	{
		std::cout << rootData << " " << rootLeftData << " " << rootRightData << " ";
 }
	file.close();

}
*/
NodeBT* createNode(int data)
{
	NodeBT* node = new NodeBT(data);
	return node;
}

static bool flag = true;
bool isBst(NodeBT* root)
{

	if (root == NULL)
	{
		return true;
	}

	if (root->left != NULL && root->left->data >= root->data)
	{
		return false;
	}
	if (root->left != NULL && root->left->right != NULL &&
		(root->left->right->data > root->data || root->left->right->data <root->left->data))
	{
		return false;
	}
	if (root->right != NULL&& root->right->data < root->data)
	{
		return false;
	}
	if (root->right != NULL && root->right->left != NULL &&
		(root->right->left->data < root->data || root->right->left->data > root->right->data))
	{
		return false;
	}
	isBst(root->left);
	isBst(root->right);
}

static int hightLeft = 0;
static int higtRigh = 0;
bool BalanceTree(NodeBT* root)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->left != NULL)
	{
		++hightLeft;

	}
	if (root->right != NULL)
	{
		++higtRigh;
	}
	if (higtRigh - hightLeft > 1 || hightLeft - higtRigh > 1)
	{
		return false;
	}

	if (root->left == NULL && root->right!= NULL && (root->right->right != NULL || root->right->left != NULL))
	{
		return false;
	}
	if (root->right == NULL && root->left!=NULL &&(root->left->right != NULL || root->left->left != NULL))
	{
		return false;
	}
	
	BalanceTree(root->left);
	BalanceTree(root->right);


}
static int hightLeftP= 0;
static int higtRighP= 0;
bool PerfectBalanceTree(NodeBT* root)
{

	if (root == NULL)
	{
		return true;
	}

	if (root->left != NULL && root->right==NULL)
	{
		return false;

	}

	if (root->left ==NULL && root->right !=NULL)
	{
		return false;

	}

	PerfectBalanceTree(root->left);
	PerfectBalanceTree(root->right);

}

void WhatTypeOftheTreeIs(NodeBT * root)
{
	if (PerfectBalanceTree(root) == 1)
	{
		std::cout << "PerfectBalanceTree: " << PerfectBalanceTree(root) << std::endl;
	}
	else if (PerfectBalanceTree(root) != 1 && BalanceTree(root) == 1)
	{
		std::cout << "BalanceTree: " << BalanceTree(root) << std::endl;

	}
	else
	{
		std::cout << " Nor ofthe both:";

	}

}

void printTree(NodeBT* root)
{
	if (root == NULL)
	{
		return;
	}
	std::cout << root->data << " ";
	printTree(root->left);
	printTree(root->right);
}
int main()
{
	/*std::ifstream file;

	file.open("tree.txt");
	char bracket;
	int rootData;
	int  rootLeftData;
	int  rootRightData;
	if (!file.is_open())
	{
		std::cerr << "The file cannot be open";
		abort();
	}
	while (file >> bracket >> rootData >> bracket >> rootLeftData >> bracket >> rootRightData)
	{
		std::cout << rootData << " " << rootLeftData << " " << rootRightData << " ";
	}
	file.close();
	*/
	NodeBT* root = createNode(5);
	root->left = createNode(2);
	root->right = createNode(7);
	root->left->left = createNode(1);
	root->left->right = createNode(3);
	root->right->left = createNode(6);
	root->right->right = createNode(9);

	printTree(root);
	std::cout << std::endl;

	std::cout << "isBst: " << isBst(root) << std::endl;
	std::cout << std::endl;  
	WhatTypeOftheTreeIs(root);
	return 0;
}

