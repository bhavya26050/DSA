#include<iostream>
using namespace std;

bool CheckPalindrome(string str, int i , int j)
{
    if(i>j)
    return true;

    if(str[i] != str[j])
    return false;
    else
    {
        //recursive call
        return CheckPalindrome(str, i+1, j-1);
    }
    
}

int main()
{
    string name = "abbbba";
    cout<<endl;

    bool isPalindrome = CheckPalindrome(name , 0 , name.length()-1);

    if(isPalindrome)
    cout<<"It is Palindrome"<<endl;
    else
    cout<<"Not an Palindrome"<<endl;

    return 0;  
} 