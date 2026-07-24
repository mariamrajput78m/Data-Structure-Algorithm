#include<iostream>
using namespace std;

struct Tree 
{
    int data;
    Tree *right;
    Tree *left;
};
Tree *createNode(int key)
{
	Tree * newnode = new Tree();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	
    if(key == -1)
    {
        return NULL;
    }
	return newnode;	
}
Tree *insert(Tree *root,int x)
{
    if(root == NULL)
    {
        return createNode(x);
    }

    // Insert in left if empty
    if(root->left == NULL)
    {
        root->left = insert(root->left,x);
    }

    // Otherwise insert in right
    else if(root->right == NULL)
    {
        root->right= insert(root->right,x);
    }

    else
    {
        root->left = insert(root->left,x);
    }
    return root;
}



Tree *search_IN_BT(Tree *root,int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data == key)
    {
        cout<<"Value found!"<<endl;
        return root;
    }
    Tree *leftSearch = search_IN_BT(root->left,key);

    if(leftSearch != NULL)
    {
        return leftSearch;
    }

    return search_IN_BT(root->right,key);

}

int sum_of_leafNode(Tree*root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    return sum_of_leafNode(root->left) + 
    sum_of_leafNode(root->right);

}

int sum_of_AllNode(Tree*root)
{
    if(root == NULL)
    {
        return 0;
    }

    return root->data +
    sum_of_AllNode(root->left) + 
    sum_of_AllNode(root->right);

}
void preorder(Tree *root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Tree *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void postorder(Tree *root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

int main()
{
    cout<<"Binary Tree"<<endl;
    Tree *root = NULL;

    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,-1);
    root = insert(root,-1);
    root = insert(root,8);
    root = insert(root,7);
    root = insert(root,-1);
    root = insert(root,-1);



    search_IN_BT(root,7);

    preorder(root);

    cout<<endl;

    cout<<"Sum of Leaf Nodes"<<endl;
    int sum = sum_of_leafNode(root);
    cout<<sum;

    cout<<endl;

    cout<<"Sum of All Nodes"<<endl;
    int sum_all = sum_of_AllNode(root);
    cout<<sum_all;
}