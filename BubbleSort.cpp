#include<iostream>
using namespace std;

//swaping function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//BubbleSort Function
void BubbleSort(int arr[], int num)
{
    for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<num-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    //print swapped array
    cout<<"Swapping after BubbleSort"<<endl;
    for(int i=0; i<num; i++)
    {
        cout<<arr[i]<<"\t";
    }
}

int main()
{
    int num;
    cout<<"Enter array size"<<endl;
    cin>>num;
    int arr[num];
    cout<<"Enter array elements"<<endl;
    for(int i=0; i<num; i++)
    {
        cout<<"Enter "<<i<<" number : "<<endl;
        cin>>arr[i];
    }
    BubbleSort(arr, num );
}