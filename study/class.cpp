#include<iostream>
// #include "Hero.cpp" // we can also create class in another file also
using namespace std;

class Hero {


    //properties
    
    private:
    int health;
    
    
    public:
    // int health;
    char level;

    Hero() {
        cout<<"Constructor  called"<<endl;
    }

    //parameterised constructor
    Hero(int health){
       this -> health = health;
    }

    int getHealth() {
        return health;
    }
    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health=h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    //empty class size = 1



};

int main()
{

    //object created statically
    Hero ramesh;

    //dynamically
    Hero *h = new Hero;











    //static allocation
    // Hero a;
    // cout<<"Level is "<<a.level<<endl;
    // cout<<"Health is "<<a.getHealth()<<endl;

    // //dynamically allocation
    // Hero *b = new Hero;
    // b->setHealth(70);
    // b->setLevel('A');
    // cout<<"Level is "<<(*b).level<<endl;
    // cout<<"Health is "<<(*b).getHealth()<<endl;

    // cout<<"Level is "<<b->.level<<endl;
    // cout<<"Health is "<<b->.getHealth()<<endl;


    // //creation of object
    // // Hero h1;

    // // cout<<"Size of"<<sizeof(h1)<<endl;

    // Hero ramesh;



    // //use setter
    // ramesh.setHealth(70);
    // // ramesh.health=70;
    // ramesh.level='A';

    //   cout<<"ramesh health is "<<ramesh.getHealth()<<endl;

    // // cout<<"Health is "<<ramesh.health<<endl;
    // cout<<"level is "<<ramesh.level<<endl; 

    return 0;
}