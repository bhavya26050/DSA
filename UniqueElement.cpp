#include<iostream>
using namespace std;
int findUnique(int *arr , int size)
{
    int ans=0;

    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
    
}
int main()
{
    int arr[9]={1,2,1,3,3,4,2,4,5};
    int ans = findUnique(arr,9);
    cout<<ans;   
}