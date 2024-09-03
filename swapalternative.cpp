#include<iostream>
using namespace std;

void printArray(int arr[] , int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void swapAlternate(int arr[] , int size)
{
    for (int i = 0; i < size; i=i+2)
    {
        if(i+1 < size)
        {
            swap(arr[i] , arr[i+1]);
        }
        
    }
    
}
int main()
{
    int EVEN[8] = {5,2,4,6,8,9,1,3};
    int ODD[5] = {1,2,3,4,5};
    swapAlternate(EVEN , 8);
    printArray(EVEN , 8);
    swapAlternate(ODD , 5);
    printArray(ODD , 5);
}