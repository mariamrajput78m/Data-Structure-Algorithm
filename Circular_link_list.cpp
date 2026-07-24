#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *tail = NULL;

	void createlist()
	{
		char x;
		do
		{
			Node *newnode = new Node;
			cout<<"Enter the new Node value: "<<endl;
			cin>>newnode->data;
			newnode->next = NULL;
				
			if(tail == NULL)
			{
				tail = newnode;
                tail->next = tail;
			}
			else
			{
                newnode->next = tail->next;
                tail->next = newnode;
                tail = newnode;
			}
	
		cout<<"press N / n for exit or to continue press anyother key : ";
		cin>>x;
			
		} while(x != 'N' and x != 'n');
	}

    void insert_at_head()
    {
        Node *newnode = new Node;
		cout<<"Enter value of new node : "<<endl;
		cin>>newnode->data;
		newnode->next = NULL;
		if(tail == NULL)
		{
			tail = newnode;
            tail->next = tail;
		}
		else
		{
			newnode->next = tail->next;
			tail->next = newnode;
		}
    }

    void insert_at_tail()
    {
        Node *newnode = new Node;
		cout<<"Enter value of new node : "<<endl;
		cin>>newnode->data;
		newnode->next = NULL;
		if(tail == NULL)
		{
			tail = newnode;
            tail->next = tail;
		}
		else
		{
			newnode->next = tail->next;
			tail->next = newnode;
            tail = newnode;
		}
    }

    void display()
    {
		int size;
		Node *temp = tail->next;
		do
		{
			size++;
			cout<<temp->data<<" ";
			temp = temp->next;
		} while (temp != tail->next);
    }

	void delete_duplicate()
	{
		Node *temp = tail->next;
		do
		{
			Node *next = temp->next;
			Node *prev = temp;
			while(next != tail->next)
			{
				if(temp->data == next->data)   
				{
					if(next == tail)
					{
						tail = prev;
					}
					prev->next = next->next;
					Node *delete_node = next;
					next = next->next;
					delete delete_node;
				}
				else
				{
					prev = next;
					next = next->next;
				}
				
			}
		temp = temp->next;

		} while (temp != tail->next);
		
	}
int main()
{
    createlist();
    insert_at_head();
    insert_at_tail();
    display();
	delete_duplicate();
    return 0;
}