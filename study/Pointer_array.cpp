#include<iostream>
using namespace std;
int main()
{
    // int arr[10] = {2,4,6,8,10,12,14,16,18,20};
    // cout<<"Address of 1st memory block is : "<<arr<<endl;
    // cout<<"Address of 1st memory block is : "<<&arr[1]<<endl;
    // cout<<"4th "<<*arr<<endl;
    // cout<<"5th "<<*arr + 1<<endl;
    // cout<<"6th "<<*(arr+1)<<endl;
    // cout<<"7th "<<(*arr) + 1<<endl;
    // int i = 3;
    // cout<<i[arr];

    // int temp[10] = {1,2};
    // cout<<sizeof(temp)<<endl;
    // cout<<sizeof(*temp)<<endl;
    // cout<<sizeof(&temp)<<endl;

    // int *ptr = &temp[0];
    // cout<<sizeof(ptr)<<endl;
    // cout<<sizeof(*ptr)<<endl;
    // cout<<sizeof(&ptr)<<endl;

//     int a[20] = {1,2,3,4};
//     cout<<&a[0]<<endl;
//     cout<<&a<<endl;
//     cout<<a<<endl;

//     int *p = &a[0];
//     cout<<p<<endl;
//     out<<*p<<endl;
//     cout<<&p<<endl;

        int arr[10];
        //arr = arr+1; //ERROR
        int *ptr = &arr[0];
        ptr = ptr + 1;
        cout<<ptr<<endl;


    return 0;
}