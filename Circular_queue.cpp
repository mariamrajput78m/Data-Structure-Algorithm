#include<iostream>
using namespace std;

#define n 5

string queue[n];
int front = -1;
int rear = -1;

void enqueue()
{
    string x;
	char choice;
	do
	{
        cout<<"Enter value of x: "<<endl;
        cin.ignore();          
        getline(cin, x);

        if(front == 0 && rear == n - 1 || (rear + 1) % n == front)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }

        if(front == -1)
        {
            front = rear = 0;
        }
        else 
        {
            rear = (rear + 1) % n;
        }

        queue[rear] = x;
    		
    cout<<"press N / n for exit or to continue press anyother key : ";
	cin>>choice;
			
	} while(choice != 'N' and choice != 'n');
}

void dequeue()
{
    if(front == -1)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    cout<<"Deleted value: "<<queue[front]<<endl;

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % n;
    }
}

void display()
{
    if(front == -1)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    cout<<"Queue has: ";
    int i = front;
    while(true)
    {
        cout<<queue[i]<<" ";

        if(i == rear)
        break;

        i = (i + 1) % n;
    }
}

void Front()
{
    if(front == -1)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }

    cout<<"Front element of Queue: "<<queue[front]<<endl;
}

int main()
{
    int choice;

    do
    {
        cout<<"\n---Circular QUEUE MENU ---"<<endl;
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



