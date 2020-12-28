#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node()
        {
            data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinklist
{
public:
    Node* head;

    DoublyLinklist()
    {
        head = NULL;
    }

    //insert node at end
    void insertEnd(Node* n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
            cout<<temp->data<<" added at end"<<endl; 
        }
    }

    //insert node at start before head
    void insertBefore(Node* n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            //Node* temp = head;
            head->prev = n;
            n->next = head;
            head = n;
            cout<<"Data added"<<endl; 
        }
    }

    //insert after specific node
    void insertAfter(int aftr, Node* n)
    {
        Node* temp = head;
        while (temp != NULL && temp->data != aftr)
        {
            temp = temp->next;
        }
        Node* nextNode = temp->next;
        if (temp->data == aftr)
        {
            // n->next = temp->next;
            // temp->next = n;
            // n->prev = temp;

            n->next = nextNode;
            nextNode->prev = temp;
            n->prev = temp;
            temp->next = n;

            cout<<"Data inserted after "<<aftr<<endl;
        }
    } 

    //delete specific node
    void deleteNode(int value)
    {
        Node* temp = head;
        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        if (head->data == value)
        {
            head = head->next;
            cout<<"Unlinking done"<<endl;
        }
        else
        {
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if (nextNode == NULL)
            {
                prevNode->next = NULL;
                cout<<"last node unlink"<<endl;
            }
            else
            {
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                cout<<"Node unlink"<<endl;
            }
        }
    }

    //print
    void print()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }  
};


int main()
{
    DoublyLinklist dl;
    int value, option,after;

    do
    {
        cout<<"------------------"<<endl;
        cout<<"1. Insert End()"<<endl;
        cout<<"2. Insert Before()"<<endl;
        cout<<"3. Insert After()"<<endl;
        cout<<"4. delete Node()"<<endl;
        cout<<"5. print()"<<endl;
        cout<<"------------------"<<endl;
        cout<<"Enter option"<<endl;
        cout<<"------------------"<<endl;
        cin>>option;
        Node* n = new Node();

        switch (option)
        {
        case 1:
            cin>>value;
            n->data = value;
            dl.insertEnd(n);
            cout<<"value inserted at end"<<endl;
            break;
        
        case 2:
            cin>>value;
            n->data = value;
            dl.insertBefore(n);
            cout<<"Value inserted at front"<<endl;
            break;

        case 5:
            dl.print();
            break;

        case 3:
            cout<<"Enter value after that you want to insert node"<<endl;
            cin>>after;
            cout<<"Enter data"<<endl;
            cin>>value;
            n->data = value;
            dl.insertAfter(after, n);
            break; 

        case 4:
            cout<<"Enter data"<<endl;
            cin>>value;
            dl.deleteNode(value);
            break;       

        default:
            cout<<"Enter proper option"<<endl;
        }

    } while (option != 0);
    
}