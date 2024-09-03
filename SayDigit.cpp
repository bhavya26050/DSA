#include<iostream>
#include<string.h>
using namespace std;

void SayDigit(int n , string arr[])
{
    //base case
    if(n == 0)
    {
        return;
    }

    //processing
    int digit = n%10;
    n = n /10;
    

    SayDigit(n , arr);
    cout<<arr[digit]<<" ";
     
}

int main()
{
    string arr[10] = {"Zero" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine"};
    int n;
    cin>>n;
    cout<<endl;
    SayDigit(n,arr);

} 