#include<iostream>
using namespace std;

#define Size 10


struct node
{
	int item;
	node *left;
	node *right;
};

void tree(node *temp, node *root);
void InOrder(node *root);
void PreOrder(node *root);
void PostOrder(node *root);
//void PrintTree(node *root);

int main()
{
	node *root = new node;

	cout << "Data : ";

	for (int i = 0; i < Size; i++)
	{
		if (i == 0)						//Creating Root Node
		{
			root->item = rand() % Size;
			root->left = NULL;
			root->right = NULL;
			cout << root->item << " ";  

		}
		else							//Creating Child Nodes
		{
			node *temp = new node;
			temp->item = rand() % Size;
			temp->left = NULL;
			temp->right = NULL;
			cout << temp->item << " ";

			tree(temp, root);		  //Creating Tree
		}
	}

	cout << endl << endl;

	//Printing Data

	cout << "Inorder :";
	InOrder(root);
	cout << endl << endl;

	cout << "Preorder :";
	PreOrder(root);
	cout << endl << endl;

	cout << "Postorder :";
	PostOrder(root);
	cout << endl << endl;
}

void tree(node *temp, node *root)		//Creating Binary Tree
{
	if (temp->item < root->item)
	{
		if (root->left == NULL)
		{
			root->left = temp;
		}
		else
		{
			tree(temp, root->left);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = temp;
		}
		else
		{
			tree(temp, root->right);
		}
	}
}

//Traversel Methods 

void InOrder(node *root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->item << " ";
		InOrder(root->right);
	}
}

void PreOrder(node *root)
{
	if (root != NULL)
	{
		cout << root->item << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PostOrder(node *root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->item << " ";
	}
}

