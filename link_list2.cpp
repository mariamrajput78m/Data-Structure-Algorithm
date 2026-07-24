//Mariam
//70176114
#include<iostream>
using namespace std;


void createlist();
void Display();
int length();
void Insert_at_head();
void Insert_at_tail();
void Insert_before_position();
void Insert_evenbefore_position();
void Tailtohead();
void sortDescending();
void sortAescending();
void Insert_at_position();
void Insert_after_value();
void Delete_head();
void Delete_tail();
void Delete_position();
void Delete_value();
void HeadtoTail();
void Swap_nodes();
void reverse();
void delete_duplicate();



struct Node
{
	int data;
	Node *next;
};
Node *head = NULL;

int main()
{
	int choice;
	int end;
	
	do
	{
		cout << "\n===== Single LINKED LIST MENU =====\n";
		cout<<"1: Create link list "<<endl;
		cout<<"2: Get length of link list "<<endl;
		cout<<"3: Display link list "<<endl;
		cout<<"4: Insert at head "<<endl;
		cout<<"5: Insert at tail "<<endl;
        cout<<"6: Insert before Position "<<endl;
		cout<<"7: Insert even before Position "<<endl;
		cout<<"8: Sort in Aescending Order "<<endl;
		cout<<"9: Sort in Descending Order "<<endl;
		cout<<"10: Tail to Head "<<endl;
		cout<<"11: Head to Tail "<<endl;
		cout<<"12: Insert at Position "<<endl;
		cout<<"13: Insert after Value "<<endl;
		cout<<"14: Delete Head "<<endl;
		cout<<"15: Delete Tail "<<endl;
		cout<<"16: Delete at Position "<<endl;
		cout<<"17: Delete by Value "<<endl;
		cout<<"18: Swap Nodes "<<endl;
		cout<<"19: Reverse LL "<<endl;
		cout<<"20: Delete Duplicates "<<endl;
		cout<<"-------Press any option Given Above-------"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					createlist();
					break;
				}
			case 2:
				{
					cout<<"Length of current link list : "<<length()<<endl;
					break;
				}
			case 3:
				{
					Display();
					break;
				}
			case 4:
				{
					Insert_at_head();
					break;
				}
			case 5:
				{
					Insert_at_tail();
					break;
				}
            case 6:
                {
                    Insert_before_position();
                    break;
                }
			case 7:
                {
                    Insert_evenbefore_position();
                    break;
                }
			case 8:
				{
					sortAescending();
					break;
				}
			case 9:
				{
					sortDescending();
					break;
				}

			case 10:
				{
					Tailtohead();
					break;
				}

			case 11:
				{
					Tailtohead(); 
					break;
				}
			case 12:
				{
					Insert_at_position();
					break;
				}
			case 13:
				{
					Insert_after_value();
					break;
				}
			case 14:
				{
					Delete_head();
					break;
				}
			case 15:
				{
					Delete_tail();
					break;
				}
			case 16:
				{
					Delete_position();
					break;
				}
			case 17:
				{
					Delete_value();
					break;
				}
			case 18:
				{
					Swap_nodes();
					break;
				}
			case 19:
				{
					reverse();
					break;
				}

			case 20:
				{
					delete_duplicate();
					break;
				}
			default:
				{
					cout<<"Invalid choice "<<endl;
				}
			
		}
		
		cout<<"Press 0 for exit and any other key for Main Menu :";
		cin>>end;
		
	} while(end != 0);
	
	return 0;
}

	
	void createlist()
	{
		char x;
		do
		{
			Node *newnode = new Node;
			cout<<"Enter the new Node value: "<<endl;
			cin>>newnode->data;
			newnode->next = NULL;
				
			if(head == NULL)
			{
				head = newnode;
			}
			else
			{
				Node *temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
						
				}
					temp->next = newnode;
			}
	
		cout<<"press N / n for exit or to continue press anyother key : ";
		cin>>x;
			
		} while(x != 'N' and x != 'n');
	}
	
	void Insert_at_head()
	{
		Node *newnode = new Node;
		cout<<"Enter value of new node : "<<endl;
		cin>>newnode->data;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}

	}
	
	void Insert_at_tail()
	{
		Node *newnode = new Node;
		cout<<"Enter value of new node : "<<endl;
		cin>>newnode->data;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
		}
		else
		{
			Node *temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
				
			}
			temp->next = newnode;
		}
	}

	void Display()   
	{
		Node *temp = head;
		if(head == NULL)
		{
			cout<<"List is empty "<<endl;
			return;
		}
		while (temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;	
	}

	void Insert_evenbefore_position()
	{
		int pos;
		cout<<"Enter position : "<<endl;
		cin>>pos;

		Node *newnode = new Node;
		cout<<"Enter value of new node : "<<endl;
        cin>>newnode->data;
        newnode->next = NULL;

		if(newnode->data % 2 != 0)
		{
			cout<<"Node is Odd "<<endl;
			return;
		}

		if(pos == 1)
        {
            newnode->next = head;
			head = newnode;
			return;
        }
    
        Node *temp = head;

        for(int i = 1 ; i < pos - 1 ; i++)
        {
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        temp->next = newnode;


	}

    void Insert_before_position()
    {
        int pos;
        Node *newnode = new Node;
        cout<<"Enter value of new node : "<<endl;
        cin>>newnode->data;
        newnode->next = NULL;

        cout<<"Enter position : "<<endl;
        cin>>pos;

        if(pos == 1)
        {
            newnode->next = head;
			head = newnode;
			return;
        }
    
        Node *temp = head;

        for(int i = 1 ; i < pos - 1 ; i++)
        {
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        temp->next = newnode;
		cout<<"Node is added "<<endl;
    }
	
	int length()
	{
		Node *temp = head;
		int size = 0;
		while(temp != NULL)
		{
			size ++;
			temp = temp->next;
		}
		cout<<endl;
		return size;
	}

	void Tailtohead()
	{
		Node *prev = NULL;
		Node *temp = head;
		Node *next = NULL;

		while(temp != NULL)
		{
			next = temp->next;   
			temp->next = prev;   
			prev = temp;         
			temp = next;         
		}
		head = prev; 
	}

	void Insert_at_position()
	{
			int pos;
			cout<<"Enter position: ";
			cin>>pos;

			Node *newnode = new Node;
			cout<<"Enter value: ";
			cin>>newnode->data;

			if(pos == 1)
			{
				newnode->next = head;
				head = newnode;
				return;
			}

			Node *temp = head;
			for(int i = 1; i < pos-1; i++)
			{
				temp = temp->next;
			}

			newnode->next = temp->next;
			temp->next = newnode;
	}

	void Insert_after_value()
		{
			int val;
			cout<<"Enter value after which to insert: ";
			cin>>val;

			Node *temp = head;

			while(temp != NULL && temp->data != val)
			{
				temp = temp->next;
			}

			if(temp == NULL)
			{
				cout<<"Value not found\n";
				return;
			}

			Node *newnode = new Node;
			cout<<"Enter new value: ";
			cin>>newnode->data;

			newnode->next = temp->next;
			temp->next = newnode;
		}

	void Delete_head()
		{
			if(head == NULL)
			{
				cout<<"List is empty\n";
				return;
			}

			Node *temp = head;
			head = head->next;
			delete temp;
		}

	void Delete_tail()
		{
			if(head == NULL)
			{
				cout<<"List is empty\n";
				return;
			}

			Node *temp = head;
			Node *prev = NULL;

			while(temp->next != NULL)
			{
				prev = temp;
				temp = temp->next;
			}

			if(prev == NULL) // only one node
			{
				head = NULL;
			}
			else
			{
				prev->next = NULL;
			}

			delete temp;
		}

	void Delete_position()
		{
			int pos;
			cout<<"Enter position to delete: ";
			cin>>pos;

			if(head == NULL)
			{
				cout<<"List is empty\n";
				return;
			}

			Node *temp = head;
			Node *prev = NULL;

			if(pos == 1)
			{
				head = head->next;
				delete temp;
				return;
			}

			for(int i = 1; i < pos && temp != NULL; i++)
			{
				prev = temp;
				temp = temp->next;
			}

			if(temp == NULL)
			{
				cout<<"Invalid position\n";
				return;
			}

			prev->next = temp->next;
			delete temp;
		}

	void Delete_value()
		{
			int val;
			cout<<"Enter value to delete: ";
			cin>>val;

			Node *temp = head;
			Node *prev = NULL;

			if(temp != NULL && temp->data == val)
			{
				head = temp->next;
				delete temp;
				return;
			}

			while(temp != NULL && temp->data != val)
			{
				prev = temp;
				temp = temp->next;
			}

			if(temp == NULL)
			{
				cout<<"Value not found\n";
				return;
			}

			prev->next = temp->next;
			delete temp;
		}

	void HeadtoTail()
		{
			if(head == NULL || head->next == NULL)
				return;

			Node *temp = head;

			while(temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = head;
			head = head->next;
			temp->next->next = NULL;
		}


	void sortAescending()
	{
		Node *temp = head;
		int swap;
		if(head == NULL)
		{
			cout<<"List is empty\n";
			return;
		}

		while(temp != NULL)
		{
			Node *next_node = temp->next;

			while(next_node != NULL)
			{
				if(temp->data > next_node->data)
				{
					swap = temp->data;
					temp->data = next_node->data;
					next_node->data = swap;
				}
				next_node = next_node->next;
			}
			temp = temp->next;
		}
	}


	void sortDescending()
	{
		Node *temp = head;
		int swap;
		if(head == NULL)
		{
			cout<<"List is empty\n";
			return;
		}

		while(temp != NULL)
		{
			Node *next_node = temp->next;

			while(next_node != NULL)
			{
				if(temp->data < next_node->data)
				{
					swap = temp->data;
					temp->data = next_node->data;
					next_node->data = swap;
				}
				next_node = next_node->next;
			}
			temp = temp->next;
		}
	}

	void Swap_nodes()
	{
		int posX, posY;
		cout<<"Enter first position: ";
		cin>>posX;
		cout<<"Enter second position: ";
		cin>>posY;

		if(posX == posY)
			return;

		Node *prevX = NULL, *tempX = head;
		Node *prevY = NULL, *tempY = head;

		
		for(int i = 1; tempX != NULL && i < posX; i++)
		{
			prevX = tempX;
			tempX = tempX->next;
		}

		
		for(int i = 1; tempY != NULL && i < posY; i++)
		{
			prevY = tempY;
			tempY = tempY->next;
		}

		if(tempX == NULL || tempY == NULL)
		{
			cout<<"Invalid positions\n";
			return;
		}

			if(prevX != NULL)
			{
				prevX->next = tempY;
			}
			else
				head = tempY;

			if(prevY != NULL)
			{
				prevY->next = tempX;
			}
			else
				head = tempX;

		Node *swap;
		swap = tempX->next;
		tempX->next = tempY->next;
		tempY->next = swap;
	}

	void reverse()
	{
		if(head == NULL)
		{
			cout<<"Link List is Empty!"<<endl;
			return;
		}

		Node *current = head;
		Node *next = NULL;
		Node *prev = NULL;
		while(current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}

	void delete_duplicate()
	{
		if(head == NULL)
		{
			cout<<"Empty"<<endl;
			return;
		}

		Node *current = head;
		while(current != NULL)
		{
			Node *prev = current;
			Node *temp = current->next;
			while(temp != NULL)
			{
				if(temp->data == current->data)
				{
					Node *del = temp;
					prev->next = temp->next;
					temp = temp->next;
					delete del;
				}
				else
				{
					prev = temp;
					temp = temp->next;
				}
			}
			current = current->next;
		}
	}

