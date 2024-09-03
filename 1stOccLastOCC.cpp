#include<iostream>
using namespace std;

int FirstOcc(int arr[] , int size , int key)
{
    int start=0;
    int end=size-1;
    int mid=start + (end-start)/2;
    int ans=-1;
    while (start<=end)
    {
        if(arr[mid] == key)
        {   
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key)
        {
            start = mid+1;
        }
        else if(arr[mid] > key)
        {
            end = mid-1;
        }
        mid = start + (end-start)/2;
        
    }
    return ans;
}

int LastOcc(int arr[] , int size , int key)
{
    int start=0;
    int end=size-1;
    int mid=start + (end-start)/2;
    int ans=-1;
    while (start<=end)
    {
        if(arr[mid] == key)
        {   
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key)
        {
            start = mid+1;
        }
        else if(arr[mid] > key)
        {
            end = mid-1;
        }
        mid = start + (end-start)/2;
        
    }
    return ans;
}

int main()
{
    int EVEN[6] = {1,2,2,2,3,4};
    int ODD[5] = {1,2,3,3,5};
    cout<<"First occurence of 2 is : "<<FirstOcc(EVEN, 6, 2)<<endl;
    cout<<"First occurence of 2 is : "<<LastOcc(EVEN, 6, 2)<<endl;
    return 0;
}