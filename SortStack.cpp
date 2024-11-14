#include<iostream>
#include<stack>
using namespace std;

void SortStack(stack<int> &s)
{
    stack<int>temp;
    while(!s.empty())
    {
        int tempTop=s.top();
        s.pop();
        while(!temp.empty() && temp.top()<tempTop)
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(tempTop);
    }
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
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
    s.push(100);
    s.push(8);
    s.push(5);
    s.push(10);
    s.push(55);
    cout<<"Before : ";
    Show(s);
    cout<<"\nAfter : ";
    SortStack(s);
    Show(s);
}