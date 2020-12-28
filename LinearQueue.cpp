#include<iostream>
#include<string>

using namespace std;

class LinearQueue
{
private:
    int arr[5];
    int front , rear;
public:
    // no args constructor
    LinearQueue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }  
    }

    //check whether queue is empty or not 
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //check whether queue is full or not
    bool isFull()
    {
        if (rear == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //enter values in a queue
    void enque(int value)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return; 
        }
        else if(isEmpty())
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        } 
    }

    //remove values from a queue
    int dequeue()
    {
        int x;
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1; 
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }  
    }

    //display queue
    void Display()
    {
        for(int i=0; i<5; i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
};


int main()
{
    LinearQueue lq;
    int value, option;

    do
    {
        cout<<"----------------------------"<<endl;
        cout<<"1. isEmpty()"<<endl;
        cout<<"2. isFull()"<<endl;
        cout<<"3. enqueue()"<<endl;
        cout<<"4. dequeue()"<<endl;
        cout<<"5. Display()"<<endl;
        cout<<"Enter option"<<endl;
        cout<<"----------------------------"<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            if (lq.isEmpty())
            {
                cout<<"Queue is empty"<<endl;
            }
            else
            {
                cout<<"Queue is not empty"<<endl;
            }
            break;

        case 2:
            if (lq.isFull())
            {
                cout<<"queue is full"<<endl;
            }
            else
            {
                cout<<"queue is not full"<<endl;
            } 
            break;

        case 3:
            cout<<"Enter number for queue"<<endl;
            cin>>value;
            lq.enque(value);
            break;

        case 4:
            cout<<"deque process"<<endl;
            cout<<lq.dequeue()<<endl;
            break;

        case 5:
            cout<<"Queue values are :"<<endl;
            lq.Display();
            break;

        case 0:
            break;
        default:
           cout<<"Enter proper options"<<endl;
        }

    } while (option !=0);
    
}