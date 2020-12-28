#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number you want to see a table :"<<endl;
    cin>>num;

    cout<<"Table is : "<<endl;
    for(int i=1; i<=10; i++)
    {
        int ans = num * i;
        cout<<num<<" * "<<i<<"="<<ans<<endl;
    }
}