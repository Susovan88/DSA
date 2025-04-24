#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Vehicle{
    public:
    int speed;
    int tyreSize;
    string name;
    Vehicle(){
        cout<<"call vehicle constructor."<<endl;
    };
};
class Car:public Vehicle{
    public:
    int numberOfSit;
    Car(){
        cout<<"call car constructor."<<endl;
    };
};
class Bike : public Vehicle{
    public:
    int lights;

    Bike(){
        cout<<"call bike constructor."<<endl;;
    };
};

class A{
    public:
    int a_public;
    protected:
    int a_protected;
    private:
    int a_private;
    
    public:
    A(){
        cout<<"call A constructor"<<endl;
    };
};

class B : public A{
    public:
    int b_public;

    void change(int s){
        this->a_protected=s;
        // this->a_public=s;
        // this->a_private=s;;
        cout<<this->a_protected;
    };

    B(){
        cout<<"call B constructor"<<endl;
    };
};

class C: public B{
    public:
    int c_public;

    C(){
        cout<<"call C constructor"<<endl;
    };
    void show(){
        this->a_protected=90;
    }
};


int main(){
    Bike hero;
    hero.name="Honda";
    hero.lights=2;
    hero.speed=70;

    // B b;
    // // b.a_private=9;
    // // b.a_public=0;
    // b.change(8);

    C c;
    
}