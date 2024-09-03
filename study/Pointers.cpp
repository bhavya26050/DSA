#include<iostream>
using namespace std;
int main()
{
    // int num = 5;
    // cout << num <<endl;

    // //Address of operator - &
    // cout<<"Address of num is : "<<&num<<endl;

    // int *ptr = &num;
    // cout<< " value is : "<<*ptr <<endl;
    // cout<< " Address is : "<<ptr <<endl;

    // int *q = &i;

    // int *p = 0;
    // p = &i;
    // cout<< " value is : "<<*p <<endl;

    int num = 5;
    int a = num;
    a++;
    cout<<num<<endl;

    int *p = &num;
    cout<<"before : "<<num<<endl;
    (*p)++;
    cout<<"After : "<<num<<endl;

    //copying a pointer
    int *q = p;
    cout<<q<<" - "<<p<<endl;
    cout<<*q<<" - "<<*p<<endl;

    //important concept
    
    int i = 3;
    int *t = &i;
    //cout<<(*t)++<<endl;
    *t = *t + 1;
    cout<<*t<<endl;
    cout<<"Before : "<<t<<endl;
    t = t + 1;
    cout<<"After : "<<t<<endl;



    return 0;
} 

 