#include<iostream>
// #include<stack>
using namespace std;

class Stack 
{
    //properties
    public:
    int *arr;
    int top;
    int size;

    //behaviour
    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1; 
    }

    void push(int element)
    {
        if(top == size-1)
        {
            cout<<"stack is overflow "<<endl;
        }
        else
        {
            top++;
            arr[top] = element;
        }
    }

    void pop() 
    {
        if(top == -1)
        {
            cout<<"stack is underflow"<<endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return true;
        }
        
    }


};

int main()
{
    // //creation of stack
    // stack<int> s;
    
    // //push operation
    // s.push(2);
    // s.push(3);

    // // pop operation
    // s.pop();

    // cout<<"Printing top element : "<<s.top();
    // if(s.empty())
    // {
    //     cout<<"\nStack is empty";
    // }
    // else
    // {
    //     cout<<"\nStack is not empty";
    // }

    // cout<<"\nSize of stack : "<<s.size();

    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(99);

    cout<<st.peek();
    st.pop();
    st.pop();
    st.pop(); 


    if(st.isEmpty())
    {
        cout<<"\nStack is empty";
    }
    else
    {
        cout<<"\nStack is not empty";
    }
    



    
    return 0;
}