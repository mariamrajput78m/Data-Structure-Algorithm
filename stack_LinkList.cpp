#include<iostream>
using namespace std;

struct Node
{
    int title;
    Node *next;
};
Node *top= NULL;

void push()
{
    Node *newnode = new Node;
    cout<<"Enter value of node: "<<endl;
    cin>>newnode->title;
    newnode->next = NULL;

    if(top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode = top->next;
        top = newnode;

    }
}

void pop()
{
    if(top == NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void reverse()
{
    Node *current = top;
    Node *next = NULL;
    Node *prev = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top = prev;
}

void display()
{
    if(top == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node *temp = top;
    while(temp != NULL)
    {
        cout<<temp->title<<" ";
        temp = temp->next;
    }

}

int main()
{
    int choice;

    do
    {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Reverse Stack\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                reverse();
                display();
                break;

            case 5:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}