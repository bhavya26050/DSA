#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s , int count , int n)
{
    //base case
    if(count == n/2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    //Recursive call
    solve(s ,count+1 , n);
    
    s.push(num);
}

void deleteMiddle(stack<int>&s , int n)
{
    int count = 0;
    solve(s , count , n);   
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
    stack<int>s ;
    s.push(1);
    s.push(2);
    s.push(3);
    // s.push(4);
    s.push(5);
    cout<<"Stack before deleting : ";
    Show(s);
    cout<<endl;

    deleteMiddle(s , 4);

    cout << "Stack after deleting the middle element: ";
    Show(s);
    return 0;
}