#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    while (n!=0)
    {
        if(n%2==0)
        {
            count++;
            n=n/2;
        }
        else
        {
            break;
        }
    }
    if(count>0)
    {
        cout<<"ture";
    }
    else
    {
        cout<<"false";
    }
    
}