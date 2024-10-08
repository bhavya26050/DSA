#include<iostream>
using namespace std;

char toLowerCase(char ch)
{
    if(ch >='a' && ch<='z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
    
}

bool checkPalindrome(char a[] , int n)
{
    int s = 0;
    int e = n-1;

    while (s<=e)
    {
        if (toLowerCase(a[s]) != toLowerCase(a[e]))
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
    
}

void Reverse(char name[] , int n)
{
    int s = 0;
    int e = n - 1;
    while (s<e)
    {
        swap(name[s],name[e]);
        s++;
        e--;
    }
    
}

int GetLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0' ; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char name[20] ; 
    cout<<"Enter your name: ";
    cin>>name;

    cout<<"Your name is : "<<endl;
    cout<<name;

    cout<<" Length: "<<GetLength(name) <<endl;

    cout<<" Pallindrome or not :  "<<checkPalindrome(name,6);

    cout<<" Charater is "<<toLowerCase('b');
    cout<<" Charater is "<<toLowerCase('C');


    return 0;

}