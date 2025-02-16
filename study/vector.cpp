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

v: [ 1 | 2 | 3 | 4 | ... | 999 ]
     🡑                      🡑     🡑
   front()                back() end()
     🡑
   begin()

front access the first element
back access the last element
end/cend returns an iterator to the end
begin/cbegin returns an iterator to the beginning