#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool FindRedundant(string &s)
{
    stack<char>st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isredundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isredundant = false;
                    }
                    st.pop();
                }

                if (isredundant == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
    
}

int main()
{
    string str = "(((a+b)+c))";
    if (FindRedundant(str))
    {
        cout << "Redundant" << endl;
    }
    else
    {
        cout << "Not Redundant" << endl;
    }
    return 0;

}