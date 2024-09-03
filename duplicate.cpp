#include<iostream>
using namespace std;
void duplicate(int  arr[] , int size)
{
    int ans=0;
    int count=0;
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] == arr[i+1])
        {
            count++;
            ans=arr[i];
        }
    }
    if(count>0)
    {
        cout<<"duplicate number is : "<<ans;
    }
    else
    {
        cout<<"no duplicate number is there ";
    }
    
}
int main()
{
    int arr[5] = {1,2,3,9,4};
    duplicate(arr,5);
}
