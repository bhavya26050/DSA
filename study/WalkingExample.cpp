#include<iostream>
using namespace std;

void ReachHome(int src , int dist )
{
    cout<<"SOURCE "<<src<<"  Destination  "<<dist<<endl;
    //base case
    if(src == dist)
    {
        cout<<"Reached"<<endl;
        return;
    }

    src++;

    //recursive call
    ReachHome(src , dist);
}


int main()
{
    int dist = 10;
    int src = 1;
    cout<<endl;
    ReachHome(src , dist);




    return 0;
    
}