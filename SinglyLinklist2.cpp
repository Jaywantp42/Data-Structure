#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    
        Node()
        {
            data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }    
};

class SinglyLinklist2
{
public:
    Node* head;

    SinglyLinklist2()
    {
        head = NULL;
    }
    SinglyLinklist2(Node* n)
    {
        head = n;
    }

    //Insert before
    void insertBefore(Node* n)
    {
        if(head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
            cout<<"Values inserted before"<<endl;
        }
    }

    //InsertEnd
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
            cout<<"Value inserted after"<<endl;
        } 
    }

    //Insert after a specific data
    void insertAfter(int aftr, Node* n)
    {
        Node* temp = head;
        while (temp != NULL && temp->data != aftr)
        {
            temp = temp->next;
        }
        if (temp->data == aftr)
        {
            n->next = temp->next;
            temp->next = n;
            cout<<"data inserted after "<<aftr<<endl;  
        }
    }

    //dalete data
    void deleteValue(int value)
    {
        if(head->data == value)
        {
            head = head->next;
        }
        else
        {
            Node* temp = NULL;
            Node* prevptr = head;
            Node* currptr = head->next;
            while (currptr != NULL)
            {
                if (currptr->data == value)
                {
                    temp = currptr;
                    currptr = NULL;
                }
                else
                {
                    prevptr = prevptr->next;
                    currptr = currptr->next;
                }
            }
            if (temp != NULL)
            {
                prevptr->next = temp->next;
                cout<<"Value "<<value<<" deleted"<<endl;
            }
        }   
    }

    //print
    void Print()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<"\t"<<endl;
            temp = temp->next;
        }
    }
};

int main()
{
    SinglyLinklist2 sl;
    int option, value, after;

    do
    {
        cout<<"--------------------"<<endl;
        cout<<"1. Insert Before"<<endl;
        cout<<"2. Insert End"<<endl;
        cout<<"3. Insert After"<<endl;
        cout<<"4. Delete"<<endl;
        cout<<"5. Print"<<endl;
        cout<<"Enter Option"<<endl;
        cout<<"--------------------"<<endl;

        cin>>option;
        Node* n = new Node();

        switch (option)
        {
        case 1:
            cout<<"Insert data Before"<<endl;
            cin>>value;
            n->data = value;
            sl.insertBefore(n);
            break;

        case 2:
            cout<<"Insert data at End"<<endl;
            cin>>value;
            n->data = value;
            sl.insertEnd(n);
            break;

        case 3:
            cout<<"Insert data after"<<endl;
            cin>>after;
            cout<<"insert your data"<<endl;
            cin>>value;
            n->data = value;
            sl.insertAfter(after,n);
            break;

        case 4:
            cout<<"Enter value you want to delete"<<endl;
            cin>>value;
            sl.deleteValue(value);
            break;        

        case 5:
            cout<<"Linklist is"<<endl;
            sl.Print();
            break;        
        
        default:
            cout<<"Enter pproper option"<<endl;
        }

    } while (option != 0);
    
}