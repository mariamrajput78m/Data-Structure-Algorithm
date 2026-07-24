/*You are developing a customer service application where customers are added to a queue and 
served in a first-come, first-served order. Implement a queue using a singly linked list with 
structure or class for this purpose, where each node represents a customer with the following 
attributes: 
 customer_id: a unique integer ID. 
 name: a string representing the customer's name. 
a) Implement the following functions in your queue: 
o enqueue(customer_id, name): Adds a new customer to the end of the queue. 
o dequeue(): Removes and returns the customer at the front of the queue. If the queue 
is empty, return a message indicating that no customers are in the queue. 
o display(): Displays the current list of customers in the queue from front to end. 
b) Call the above functions in Main( ) to perform the following operations and output the 
results: 
o Add three customers to the queue: (1, "Alice"), (2, "Bob"), (3, "Charlie"). 
o Serve (dequeue) one customer. 
o Add two more customers: (4, "Daisy"), (5, "Evan"). 
o Display the current queue. */

#include<iostream>
using namespace std;

struct Node
{
    int customer_id;
    string name;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue()
{
    
	char choice;
	do
	{
        Node *newnode = new Node;
        cout<<"Enter customer id: "<<endl;
        cin>>newnode->customer_id;
        cout<<"Enter name: "<<endl;
        cin>>newnode->name;

        newnode->next = NULL;

        if(rear == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }

    cout<<"press N / n for exit or to continue press anyother key : ";
	cin>>choice;
			
	} while(choice != 'N' and choice != 'n');

}

void dequeue()
{
    if(front == NULL)
    {
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    Node *temp = front;
    cout<<"Deleted customer: "<<front->customer_id<<" "<<front->name<<endl;

    front = front->next;

    if(front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}


void display()
{
    if(front == NULL)
    {
        cout<<"Queue is Empty!"<<endl;
        return;
    }

    Node *temp = front;
    cout<<"Customers : \n"<<endl;

    while(temp != NULL)
    {
        cout<<temp->customer_id<<" "<<temp->name<<endl;
        temp = temp->next;
    }
}

void Front()
{
    if(front == NULL)
    {
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    cout<<"Top of Queue: "<<front->customer_id<<" "<<front->name<<endl;

}

int main()
{
        int choice;

    do
    {
        cout<<"\n--- QUEUE MENU ---"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Front"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                Front();
                break;

            case 5:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice"<<endl;
        }

    } while(choice != 5);

    return 0;
}