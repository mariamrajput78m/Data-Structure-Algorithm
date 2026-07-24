#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node *right;
	Node *left;
};

//Node *createnode(int value,Node *root)
//{
//	int x;
//	cout<<"Enter value of x: "<<endl;
//	cin>>x;
//	
//	Node *newnode = new Node;
//	newnode->data = x;
//	
//}

Node *createNode(int key)
{
	Node * newnode = new Node();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;	
}

void inorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);

}

void preorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	cout<<root->data<<"->";
	preorder(root->left);
	preorder(root->right);
	
}

void postorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"->";
	
}

Node *insert(Node *root,int key)
{
	if(root == NULL)
	{
		return createNode(key);
	}
	if(key < root->data)
	{
		root->left = insert(root->left,key);
	}
	else if(key > root->data)
	{
		root->right = insert(root->right,key);
	}
	return root;
}

Node *search_in_BST(Node *root,int key)
{
	if(root == NULL)
	{
		cout<<"Value not found! "<<endl;
		return root;
	}
	if(root->data == key)
	{
		cout<<"Value found! "<<key<<endl;
		return root;
	}
	
	if(key < root->data)
	{
		return search_in_BST(root->left , key);
	}
	
	return search_in_BST(root->right , key);
}

Node *findMin(Node *root)
{
	while(root && root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
Node *deleteNode(Node *root,int key)
{
	if(root == NULL)
	{
		return root;
	}
	
	//transverse the node
	if(key < root->data)
	{
		root->left = deleteNode(root->left,key);
	}
	else if(key > root->data)
	{
		root->right = deleteNode(root->right , key);
	}
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		if(root->left == NULL)
		{
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}
		
		//Node with two childrens: Get the inorder successor
		Node *temp = findMin(root->right);
		root->data= temp->data;
		root->right = deleteNode(root->right,temp->data);
	}
	return root;
}

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
	Node *root = NULL;
	
	root = insert(root,8);
	root = insert(root,5);
	root = insert(root,9);
	root = insert(root,3);
	root = insert(root,10);

	
	inorder(root);
	
	cout<<endl;
	preorder(root);
	
	cout<<endl;
	postorder(root);
	
	cout<<endl;
	search_in_BST(root,5);
	
	root = deleteNode(root,9);
	inorder(root);

	cout<<endl;
	
	BFS(root);

}
