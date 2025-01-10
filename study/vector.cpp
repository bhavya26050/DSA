#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    cout<<v.capacity();
    v.push_back(1);
    cout<<v.capacity();
    v.pop_back();
    cout<<v.capacity();
    v.clear();
}