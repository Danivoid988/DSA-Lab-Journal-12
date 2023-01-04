#include <iostream> 
using namespace std;


const int MAX = 100;

class BinaryTree
{
	int data[MAX];
	int left[MAX];
	int right[MAX];
	int root;
	int numOfNodes;
public:
	
	BinaryTree()
	{
		root = -1;
		numOfNodes = 0;
		for (int i = 0; i < MAX; i++)
		{
			data[i] = 0;
			left[i] = -1;
			right[i] = -1;
		}
	}


	bool isEmpty()
	{
		return (numOfNodes == 0);
	}


	int getNumberOfNodes()
	{
		return numOfNodes;
	}


	void insertNode(int val)
	{
		if (root == -1)
		{
			root = 0;
			data[root] = val;
			left[root] = -1;
			right[root] = -1;
			numOfNodes++;
		}
		else
		{
			
			int current = root;
			int parent;
			while (true)
			{
				parent = current;
				if (val < data[current])
				{
					
					current = left[current];
					if (current == -1)
					{
						
						left[parent] = numOfNodes;
						data[numOfNodes] = val;
						left[numOfNodes] = -1;
						right[numOfNodes] = -1;
						numOfNodes++;
						break;
					}
				}
				else
				{
					
					current = right[current];
					if (current == -1)
					{
						// insert node to the right 
						right[parent] = numOfNodes;
						data[numOfNodes] = val;
						left[numOfNodes] = -1;
						right[numOfNodes] = -1;
						numOfNodes++;
						break;
					}
				}
			}
		}
	}

	 
	void inorder()
	{
		inorder(root);
	}

	
	void inorder(int current)
	{
		if (current != -1)
		{
			inorder(left[current]);
			cout << data[current] << " ";
			inorder(right[current]);
		}
	}
};


int main()
{
	
	BinaryTree bt;

	
	bt.insertNode(5);
	bt.insertNode(6);
	bt.insertNode(4);
	bt.insertNode(2);
	bt.insertNode(7);
	bt.insertNode(1);

	
	cout << "Inorder Traversal: ";
	bt.inorder();
	system("pause");
	return 0;
}
