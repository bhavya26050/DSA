#include<iostream>
using namespace std;

bool LinearSearch(int arr[] , int size , int key)
{
    //base case
    if(size == 0)
    return false;

    if(arr[0] == key)
    return true;
    else
    {
        bool remainingpart = LinearSearch(arr + 1 , size - 1 , key);
        return remainingpart;
    }
    


}

int main()
{
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 10;

    bool ans = LinearSearch(arr,size,key);

    if(ans)
    cout<<"Present "<<endl;
    else
    cout<<"Not Present "<<endl;


    return 0;
}