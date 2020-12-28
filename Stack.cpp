#include<iostream>
#include<string>

using namespace std;

class Stack
{
private:
    int top;
    int arr[5];
public:
    Stack()
    {
        top = -1;
        for(int i=0; i<5; i++)
        {
            arr[i] = 0;
        }
    }

    //ISEmpty check
    bool isEmpty()
    {
        if(top == -1)
        return true;
        else
        {
            return false;
        }  
    }

    //IsFull Check
    bool isFull()
    {
        if(top == 4)
        return true;
        else
        {
            return false;
        }  
    }

    //push into stack
    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++ ;
            arr[top] = val;
        } 
    }

    //pop from stack
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top --;
            return popvalue;
        }
    }

    //display values
    void Display()
    {
        for(int i=4; i>=0; i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack s1;
    int option, value;

    do
    {
        cout<<"Select options for stack operation"<<endl;
        cout<<"1. isEmpty()"<<endl;
        cout<<"2. isFull()"<<endl;
        cout<<"3. push()"<<endl;
        cout<<"4. pop()"<<endl;
        cout<<"5. Display()"<<endl;

        cin>>option;
        switch (option)
        {
        case 1:
            if(s1.isEmpty())
                cout<<"Stack is empty"<<endl;
            else
            {
                cout<<"Stack is not empty"<<endl;
            }   
            break;

        case 2:
            if(s1.isFull())
            {
                cout<<"Stack is full"<<endl;
            }
            else
            {
                cout<<"Stack is not full"<<endl;
            }
            break;

        case 3:
            cout<<"Enter number to push into stack"<<endl;
            cin>>value;
            s1.push(value);
            break;

        case 4:
            cout<<"Pop function called"<<endl;
            cout<<s1.pop()<<endl;
            break;  

         case 5:
            cout<<"Stack values are"<<endl;
            s1.Display();
            break;         
        default:
            cout<<"Enter proper operation number"<<endl;
        }
    } while (option!=0);
    
}