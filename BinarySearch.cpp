#include<iostream>
using namespace std;
int BinarySearch(int arr[] , int size , int key)
{
    int start=0;
    int end=size-1;
    int mid = start + (start + end)/2;

    while (start <= end)
    {
        if(arr[mid]==key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = (start + end)/2;
        
    }
    return -1;
}
int main()
{
    int EVEN[6] = {1,5,9,12,56,99};
    int ODD[5] = {1,5,9,78,99}; 
    int index = BinarySearch(EVEN,6,12);
    cout<<"Index of 18 is : "<<index<<endl;
    int indexx = BinarySearch(ODD,5,99);
    cout<<"Index of 99 is : "<<indexx<<endl;
} 