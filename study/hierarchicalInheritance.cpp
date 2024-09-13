#include<iostream>
using namespace std;

class A {
    public:
    void funct1() {
        cout<<"Function 1" <<endl;
    }
};

class B: public A  {
    public:
    void funct2() {
        cout<<"Function 2" <<endl;
    }
};

class C: public A  {
    public:
    void funct3() {
        cout<<"Function 3" <<endl;
    }
};

int main()
{
    A obj1;
    obj1.funct1();

    B obj2;
    obj2.funct1();
    obj2.funct2();

    C obj3;
    obj3.funct1();
    // obj3.funct2(); // u cant call funct2 from object C
    obj3.funct3();
    


    return 0;
}