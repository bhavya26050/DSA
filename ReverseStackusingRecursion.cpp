#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s , int a)
{
    //base case
    if(s.empty())
    {
        s.push(a);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s , a);

    s.push(num);
}

void ReverseStack(stack<int> &s )
{
    //base case
    if(s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    ReverseStack(s);

    insertAtBottom(s , num);

}

void Show(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"Before : ";
    Show(s);
    cout<<"\nAfter : ";
    ReverseStack(s);
    Show(s);

}