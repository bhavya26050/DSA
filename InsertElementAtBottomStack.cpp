#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s , int x)
{
    stack<int>temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }

    s.push(x);

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
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Before putting in the stack : ";
    Show(s);
    cout<<"\nAfter pushing element : ";
    solve(s,4);
    Show(s);

}