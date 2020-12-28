// To sort an array of size n in ascending order:
// 1: Iterate from arr[1] to arr[n] over the array.
// 2: Compare the current element (key) to its predecessor.
// 3: If the key element is smaller than its predecessor, compare it to the elements before.
// Move the greater elements one position up to make space for the swapped element.

#include<iostream>
using namespace std;

void InsertionSort(int arr[], int num)
{
    for(int i=1; i<num; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            int temp = arr[j];
            arr[j] = key;
            arr[j+1] = temp;
            j = j-1; 
        }
    }

    //print sorted array
    cout<<"Sorted array is : "<<endl;
    for(int i=0; i<num; i++)
    {
        cout<<arr[i]<<"\t";
    }
}

int main()
{
    int num;
    cout<<"Enter Array Size"<<endl;
    cin>>num;
    int arr[num];
    for(int i=0; i<num; i++)
    {
        cout<<"Enter "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    InsertionSort(arr,num);
}