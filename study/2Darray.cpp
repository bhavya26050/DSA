// int a[i];    Input for 1D Array 
// cin>>a[i];    Taking Input for 1D array
// int a[i][j];  Input for 2d Array
// cin>>a[i][j];  Taking Input for 2D array
#include<iostream>
using namespace std;

bool isPresent(int arr[][3] , int target , int row , int col)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j] == target);{
                return 1;
            }
        }
        
    }
    return 0;
}

int LargestRowSUM(int arr[][3] , int row , int col)
{
    int maxi = INT_MIN;
    int rowIndex = -1;

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + arr[i][j];
        }
        if(sum > maxi)
        {
            maxi = sum;
            rowIndex = i;
        }
    }

    cout<<"The maximum sum is : "<<maxi;
    return rowIndex;
}

// print row wise sum
void PrintSUM(int arr[][3] , int row , int col)
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + arr[i][j];
        }
        cout<<sum<<" ";
    }
}

void WavePrint(int arr[][3] , int row , int col)
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3;i++)
        {
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
        
    }
}

int main()
{
    //Taking input
    int arr[3][3];
    cout<<"Enter the elements in an array : ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>> arr[i][j];
        }
        
    }
    
    //Printing Output
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
        
    }

    // cout<<"Enter the element to search : "<<endl;
    // int target;
    // cin>>target;

    // if (isPresent(arr , target , 3 ,3) )
    // {
    //     cout<<"Element found";
    // }
    // else
    // {
    //     cout<<"Element not found";
    // }
    
    // PrintSUM(arr , 3 , 3);
    // LargestRowSUM(arr , 3 , 3);
    // WavePrint(arr , 3 , 3);

    return 0;

}