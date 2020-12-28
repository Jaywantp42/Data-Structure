#include<iostream>

using namespace std;

class ArrayEg
{
private:
    int arr[100];
    int ans;
public:
    ArrayEg()
    {
        ans = 0;
    }
    void print(int size)
    {
        cout<<"Enter array Elements"<<endl;
        for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }
        cout<<"Display"<<endl;
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};


int main()
{
    int size;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    ArrayEg ar;
    ar.print(size);
}