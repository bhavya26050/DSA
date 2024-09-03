#include<iostream>
using namespace std;

void ReverseString(string &str , int i , int j)
{
    //base case
    if(i>j)
    return;

    //swap
    swap(str[i],str[j]);
    i++;
    j--;

    //recursion call
    ReverseString(str,i,j);
}

int main()
{
    string name = "bhavya";

    ReverseString(name , 0 , name.length()-1);

    cout<<name<<endl;


    return 0;
}