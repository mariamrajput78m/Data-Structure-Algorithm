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


// ── DLL Node: has both next and prev pointer ─────────────────────────────
struct Node
{
	int data;
	Node *next;
	Node *prev;   // NEW: points to previous node
};

Node *head = NULL;
Node *tail = NULL;   // NEW: tail pointer for O(1) tail operations

int main()
{
	int choice;
	int end;

	do
	{
		cout << "\n===== Double LINKED LIST MENU =====\n";
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
					HeadtoTail();
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


// ── createlist ───────────────────────────────────────────────────────────
void createlist()
{
	char x;
	do
	{
		Node *newnode = new Node;
		cout<<"Enter the new Node value: "<<endl;
		cin>>newnode->data;
		newnode->next = NULL;
		newnode->prev = NULL;   // NEW

		if(head == NULL)
		{
			head = newnode;
			tail = newnode;   // NEW: first node is also tail
		}
		else
		{
			newnode->prev = tail;   // NEW: new node's prev = old tail
			tail->next = newnode;   // old tail points forward to new
			tail = newnode;         // NEW: update tail
		}

		cout<<"press N / n for exit or to continue press anyother key : ";
		cin>>x;

	} while(x != 'N' and x != 'n');
}


// ── Insert_at_head ───────────────────────────────────────────────────────
void Insert_at_head()
{
	Node *newnode = new Node;
	cout<<"Enter value of new node : "<<endl;
	cin>>newnode->data;
	newnode->next = NULL;
	newnode->prev = NULL;   // NEW

	if(head == NULL)
	{
		head = newnode;
		tail = newnode;   // NEW
	}
	else
	{
		newnode->next = head;    // new node points forward to old head
		head->prev = newnode;    // NEW: old head points back to new node
		head = newnode;          // update head
	}
}


// ── Insert_at_tail ───────────────────────────────────────────────────────
void Insert_at_tail()
{
	Node *newnode = new Node;
	cout<<"Enter value of new node : "<<endl;
	cin>>newnode->data;
	newnode->next = NULL;
	newnode->prev = NULL;   // NEW

	if(head == NULL)
	{
		head = newnode;
		tail = newnode;   // NEW
	}
	else
	{
		newnode->prev = tail;   // NEW: new node's prev = old tail
		tail->next = newnode;   // old tail links forward
		tail = newnode;         // NEW: update tail
	}
}


// ── Display ──────────────────────────────────────────────────────────────
void Display()
{
	Node *temp = head;
	if(head == NULL)
	{
		cout<<"List is empty "<<endl;
		return;
	}

	// Forward
	cout<<"Forward:  ";
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;

	// Backward — NEW: only possible in DLL using prev pointer
	cout<<"Backward: ";
	temp = tail;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}


// ── Insert_evenbefore_position ───────────────────────────────────────────
void Insert_evenbefore_position()
{
	int pos;
	cout<<"Enter position : "<<endl;
	cin>>pos;

	Node *newnode = new Node;
	cout<<"Enter value of new node : "<<endl;
	cin>>newnode->data;
	newnode->next = NULL;
	newnode->prev = NULL;   // NEW

	if(newnode->data % 2 != 0)
	{
		cout<<"Node is Odd "<<endl;
		return;
	}

	if(pos == 1)
	{
		newnode->next = head;
		if(head != NULL) head->prev = newnode;   // NEW
		head = newnode;
		if(tail == NULL) tail = newnode;          // NEW
		return;
	}

	Node *temp = head;
	for(int i = 1 ; i < pos - 1 ; i++)
	{
		temp = temp->next;
	}

	newnode->next = temp->next;
	newnode->prev = temp;           // NEW: new node's prev = temp
	if(temp->next != NULL)
		temp->next->prev = newnode; // NEW: next node's prev = new node
	else
		tail = newnode;             // NEW: new node is new tail
	temp->next = newnode;
}


// ── Insert_before_position ───────────────────────────────────────────────
void Insert_before_position()
{
	int pos;
	Node *newnode = new Node;
	cout<<"Enter value of new node : "<<endl;
	cin>>newnode->data;
	newnode->next = NULL;
	newnode->prev = NULL;   // NEW

	cout<<"Enter position : "<<endl;
	cin>>pos;

	if(pos == 1)
	{
		newnode->next = head;
		if(head != NULL) head->prev = newnode;   // NEW
		head = newnode;
		if(tail == NULL) tail = newnode;          // NEW
		return;
	}

	Node *temp = head;
	for(int i = 1 ; i < pos - 1 ; i++)
	{
		temp = temp->next;
	}

	newnode->next = temp->next;
	newnode->prev = temp;           // NEW
	if(temp->next != NULL)
		temp->next->prev = newnode; // NEW
	else
		tail = newnode;             // NEW
	temp->next = newnode;
	cout<<"Node is added "<<endl;
}


// ── length ───────────────────────────────────────────────────────────────
int length()
{
	Node *temp = head;
	int size = 0;
	while(temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	cout<<endl;
	return size;
}


// ── Tailtohead (Reverse the list) ────────────────────────────────────────
void Tailtohead()
{
	if(head == NULL) return;

	Node *temp = head;
	Node *swap = NULL;

	// In DLL: swap next and prev of every node
	while(temp != NULL)
	{
		swap = temp->prev;       // NEW: swap prev and next
		temp->prev = temp->next;
		temp->next = swap;
		temp = temp->prev;       // move to next node (now stored in prev)
	}

	// After loop, swap points to the old head's prev (which is new head)
	if(swap != NULL)
	{
		tail = head;             // NEW: old head becomes tail
		head = swap->prev;       // NEW: last visited node is new head
	}
}


// ── Insert_at_position ───────────────────────────────────────────────────
void Insert_at_position()
{
	int pos;
	cout<<"Enter position: ";
	cin>>pos;

	Node *newnode = new Node;
	cout<<"Enter value: ";
	cin>>newnode->data;
	newnode->next = NULL;
	newnode->prev = NULL;   // NEW

	if(pos == 1)
	{
		newnode->next = head;
		if(head != NULL) head->prev = newnode;   // NEW
		head = newnode;
		if(tail == NULL) tail = newnode;          // NEW
		return;
	}

	Node *temp = head;
	for(int i = 1; i < pos-1; i++)
	{
		temp = temp->next;
	}

	newnode->next = temp->next;
	newnode->prev = temp;           // NEW
	if(temp->next != NULL)
		temp->next->prev = newnode; // NEW
	else
		tail = newnode;             // NEW: inserted at end
	temp->next = newnode;
}


// ── Insert_after_value ───────────────────────────────────────────────────
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
	newnode->prev = temp;           // NEW
	if(temp->next != NULL)
		temp->next->prev = newnode; // NEW
	else
		tail = newnode;             // NEW
	temp->next = newnode;
}


// ── Delete_head ──────────────────────────────────────────────────────────
void Delete_head()
{
	if(head == NULL)
	{
		cout<<"List is empty\n";
		return;
	}

	Node *temp = head;
	head = head->next;

	if(head != NULL)
		head->prev = NULL;   // NEW: new head's prev = NULL
	else
		tail = NULL;         // NEW: list is now empty

	delete temp;
}


// ── Delete_tail ──────────────────────────────────────────────────────────
void Delete_tail()
{
	if(head == NULL)
	{
		cout<<"List is empty\n";
		return;
	}

	Node *temp = tail;       // NEW: directly access tail — no traversal needed
	tail = tail->prev;       // NEW: move tail back

	if(tail != NULL)
		tail->next = NULL;   // NEW: new tail's next = NULL
	else
		head = NULL;         // NEW: list is now empty

	delete temp;
}


// ── Delete_position ──────────────────────────────────────────────────────
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

	if(pos == 1)
	{
		Delete_head();
		return;
	}

	Node *temp = head;
	for(int i = 1; i < pos && temp != NULL; i++)
	{
		temp = temp->next;
	}

	if(temp == NULL)
	{
		cout<<"Invalid position\n";
		return;
	}

	if(temp->prev != NULL)
		temp->prev->next = temp->next;   // NEW: bypass using prev

	if(temp->next != NULL)
		temp->next->prev = temp->prev;   // NEW: fix next node's prev
	else
		tail = temp->prev;               // NEW: deleted node was tail

	delete temp;
}


// ── Delete_value ─────────────────────────────────────────────────────────
void Delete_value()
{
	int val;
	cout<<"Enter value to delete: ";
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

	if(temp->prev != NULL)
		temp->prev->next = temp->next;   // NEW: bypass using prev
	else
		head = temp->next;               // deleted node was head

	if(temp->next != NULL)
		temp->next->prev = temp->prev;   // NEW: fix next node's prev
	else
		tail = temp->prev;               // NEW: deleted node was tail

	delete temp;
}


// ── HeadtoTail ───────────────────────────────────────────────────────────
void HeadtoTail()
{
	if(head == NULL || head->next == NULL)
		return;

	Node *oldHead = head;

	head = head->next;       // second node becomes new head
	head->prev = NULL;       // NEW: new head's prev = NULL

	oldHead->prev = tail;    // NEW: old head's prev = old tail
	oldHead->next = NULL;    // old head is new tail
	tail->next = oldHead;    // old tail links to old head
	tail = oldHead;          // NEW: update tail
}


// ── sortAescending ───────────────────────────────────────────────────────
void sortAescending()
{
	Node *temp = head;
	int swap;
	if(head == NULL)
	{
		cout<<"List is empty\n";
		return;
	}

	// Swap data only — prev/next pointers don't change
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


// ── sortDescending ───────────────────────────────────────────────────────
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


// ── Swap_nodes ───────────────────────────────────────────────────────────
void Swap_nodes()
{
	int posX, posY;
	cout<<"Enter first position: ";
	cin>>posX;
	cout<<"Enter second position: ";
	cin>>posY;

	if(posX == posY) return;

	Node *tempX = head;
	Node *tempY = head;

	for(int i = 1; tempX != NULL && i < posX; i++)
		tempX = tempX->next;

	for(int i = 1; tempY != NULL && i < posY; i++)
		tempY = tempY->next;

	if(tempX == NULL || tempY == NULL)
	{
		cout<<"Invalid positions\n";
		return;
	}

	// Swap data values — simpler and correct for DLL
	int temp = tempX->data;
	tempX->data = tempY->data;
	tempY->data = temp;
}