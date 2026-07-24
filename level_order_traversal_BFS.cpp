//Mariam
//70176114
//TREE-BFS(Breath first Traversal)

#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        Node *left = NULL;
        Node *right = NULL;
    }
};


void BFS(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	queue <Node *> q;
	q.push(root);

	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		cout<<temp->data<<" ";

		if(temp->left)
		{
			q.push(temp->left);
		}

		if(temp->right)
		{
			q.push(temp->right);
		}
	}
}

int main()
{
    cout<<"Breath First Traversal"<<endl;

    Node *root = NULL;
    root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(2);
    root->left->right = new Node(11);

    root->right->left = new Node(5);
    root->right->right = new Node(4);

    BFS(root);
    return 0;

}