#include<iostream>
using namespace std;
int main()
{
  int num,ans=0,digit;
  cout<<"enter the number";
  cin>>num;
  while(num!=0)
  {
    digit=num%10;
    num=num/10;
    ans=ans*10+digit;
  }
  cout<<ans;
  return 0;
} 