#include<iostream>

using namespace std;

class Node
{
    private:
        // int key;
        // int data;
        // Node* next;

    public:
        int key;
        int data;
        Node* next;
        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int key, int data)
        {
            this->key = key;
            this->data = data;
            this->next = NULL; 
        }    
};

class SinglyLinklist
{
private:
    // Node* head;
public:
    Node* head;
    SinglyLinklist()
    {
        head = NULL;
    }
    SinglyLinklist(Node* n)
    {
        head = n;
    }

    //1. Check if node exist
    Node* nodeExist(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;
        while (ptr != NULL)
        {
            if(ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2. append node in linklist
    void appendNode(Node* n)
    {
        if(nodeExist(n->key)!=NULL)
        {
            cout<<"Node already exists with key value :"<<n->key<<", Append another node with diferent key value"<<endl;
        }
        else
        {
            if(head == NULL)   //this will happen for first node------------no node attach to singly linklist
            {
                head = n;
                cout<<"Node append"<<endl;
            }
            else
            {
                Node* ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout<<"Node appended"<<endl;
            }
        }
    }

    //3. Prepend node : a node attached at the start
    void prepend(Node* n)
    {
        if(nodeExist(n->key)!=NULL)
        {
            cout<<"Node already exists with key value :"<<n->key<<", Append another node with diferent key value"<<endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout<<"node prepended"<<endl;
        }
    }

    //4. Insert a node after particular node in a list
    void insertAfter(int k,Node* n)
    {
        Node* ptr = nodeExist(k);
        if(ptr == NULL)
        {
            cout<<"No node exist with key "<<k<<endl;
        }
        else
        {
            if(nodeExist(n->key)!=NULL)
            {
                cout<<"Node already exists with key value :"<<n->key<<", Append another node with diferent key value"<<endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout<<"Node inserted"<<endl;
            }
            
        }
    }

    //5. Delete node by unique key
    void deleteNodeByKey(int k)
    {
        if(head == NULL)
        {
            cout<<"Singly linklist empty"<<endl;
        }
        else
        {
            if(head->key==k)
            {
                head = head->next;
                cout<<"Node unlink with  key value "<<k<<endl;
            }
            else
            {
                Node* temp = NULL;
                Node* prevptr = head;
                Node* currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout<<"node unlink with key value "<<k<<endl;
                }
                else
                {
                    cout<<"Node node exist with key value "<<k<<endl;
                }
            }  
        }
    }

    //6. Update node's data value
    void updateNodeByKey(int k, int data)
    {
        Node* ptr =  nodeExist(k);
        if(ptr != NULL)
        {
            ptr->data = data;
            cout<<"data update successfully"<<endl;
        }
        else
        {
            cout<<"Node does not exist with key value "<<k<<endl;
        }
    }

    //7. print
    void Print()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout<<"("<<temp->key<<","<<temp->data<<")--->";
            temp = temp->next;
        }
    }
};


int main()
{
    SinglyLinklist ll;
    int option, key1, k1, data;
    do
    {
        cout<<"---------------------------------------"<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter()"<<endl;
        cout<<"4. deleteNodeAfter()"<<endl;
        cout<<"5. updateNodeData()"<<endl;
        cout<<"6. printNode()"<<endl;
        cout<<"7. STOP"<<endl;
        cout<<"Enter option"<<endl;
        cout<<"---------------------------------------"<<endl;
        cin>>option;
        Node* n = new Node();

        switch (option)
        {
        case 1:
            cout<<"Append Node operation"<<endl;
            cin>>key1;
            cin>>data;
            n->key = key1;
            n->data = data;
            ll.appendNode(n);
            break;
        
        case 2:
            cout<<"Prepend Node operation"<<endl;
            cin>>key1;
            cin>>data;
            n->key = key1;
            n->data = data;
            ll.prepend(n);
            break;

        case 3:
            cout<<"Indert Node After"<<endl;
            cin>>k1;
            cout<<"Enter key and data"<<endl;
            cin>>key1;
            cin>>data;
            n->key = key1;
            n->data = data;
            ll.insertAfter(k1,n);
            break;

        case 4:
            cout<<"delete after node"<<endl;
            cin>>k1;
            ll.deleteNodeByKey(k1);
            break;

        case 5:
            cout<<"Udate data in that key"<<endl;
            cin>>key1;
            cin>>data;
            ll.updateNodeByKey(key1,data);
            break;

        case 6:
            cout<<"Printlist"<<endl;
            ll.Print();
            break;

        case 7:
            break;

        default:
            cout<<"Enter correct option"<<endl;
        }

    } while (option != 0);
    
}