#include<iostream>
using namespace std;
void arrayIntersection( int arr[] , int arr1[] , int n , int m)
{
    int ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i]==arr1[j])
            {
                ans=arr[i];
                cout<<"intersection no. is "<<ans<<endl;
            }
        }
    }
    cout<<"no duplicate number found ";
}

int main()
{
    int arr[7] = {1,2,3,4,5,6,7};
    int arr1[3] = {1,8,9};
    arrayIntersection(arr , arr1 , 7 , 3);
}
