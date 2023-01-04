#include<iostream> 
using namespace std;

// A binary tree node 
class Node
{
public:
	int data;
	Node *left, *right;
};

// A utility function to create a new node 
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to print Inorder traversal of a given binary tree 
void printInorder(Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

// Function to print Preorder traversal of a given binary tree 
void printPreorder(Node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

// Function to print Postorder traversal of a given binary tree 
void printPostorder(Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree 
	printPostorder(node->left);

	// then recur on right subtree 
	printPostorder(node->right);

	// now deal with the node 
	cout << node->data << " ";
}

// Driver program to test above functions 
int main()
{
	// Let us construct the tree 
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);
	system("pause");
	return 0;
}
