#include<iostream>
#include<stack>
#include<string>

using namespace std;


bool isValidParentheses(string str )
{
    stack<char>s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];


        //if opening bracket , push into stack
        if ( ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        //if closing bracket , check stacktop and  pop from stack
        else
        {
            if(!s.empty())
            {
                char top = s.top();
                if((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                
            }
            else
            {
                return false;
            }
        }
    }
    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}


int main()
{
    stack<char>s;
    string str = "({[]})";
    cout << isValidParentheses(str) << endl;

    return 0;

}