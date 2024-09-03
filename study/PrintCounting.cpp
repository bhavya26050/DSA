#include<iostream>
using namespace std;

void PRINT(int n)
{
    if(n == 0){
        return ;
    }
    cout<<n<<endl;
    PRINT(n-1);
}

int main()
{
    int n;
    cin>>n;
    PRINT(n);

    return 0;
}    
