#include<iostream>

using namespace std;

class CircularQueue
{
private:
    int front, rear;
    int arr[5];
public:
    CircularQueue()
    {
        front = rear = -1;
        for(int i=0; i<5; i++)
        {
            arr[i] = 0;
        }
    }
    
    bool isEmpty()
    {
        if(front == -1 && rear == -1)
            return true;
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (front == (rear+1)%5) //if rear = 4[size(arr-1)]; with this formula comes to first index and can add value 
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout<<"Queue is full"<<endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear = (rear + 1) % 5; //// to dequeue queue using formula when it is on last position, it comes on 1st position
            arr[rear] = val;
        }   
    }

    int dequeue()
    {
        int x;
        if(isEmpty())
        {
            cout<<"Queue already empty"<<endl;
            return 0;
        }
        else if (rear == front)
        {
            x = arr[front];
            rear = front = 1;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1)%5; // to dequeue queue using formula when it is on last position, it comes on 1st position
            return x; 
        }
    }

    void Display()
    {
        for(int i=0; i<5; i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};


int main()
{
    CircularQueue cq;
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
            if (cq.isEmpty())
            {
                cout<<"Queue is empty"<<endl;
            }
            else
            {
                cout<<"Queue is not empty"<<endl;
            }
            break;

        case 2:
            if (cq.isFull())
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
            cq.enqueue(value);
            break;

        case 4:
            cout<<"deque process"<<endl;
            cout<<cq.dequeue()<<endl;
            break;

        case 5:
            cout<<"Queue values are :"<<endl;
            cq.Display();
            break;

        case 0:
            break;
        default:
           cout<<"Enter proper options"<<endl;
        }

    } while (option !=0);
}