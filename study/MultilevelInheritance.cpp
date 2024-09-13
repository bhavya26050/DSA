#include<iostream>
using namespace std;


class Animal {
    public:
    int age;
    int weight;


    public:
    void speak()
    {
        cout<<"Speaking"<<endl;
    }
};

class Dog: public Animal {

};

class GermanShepherd: public Dog {

};

int main()
{
    Dog d;
    GermanShepherd g;
    d.speak();
    cout<<d.age<<endl;
    g.speak();
    return 0;
}