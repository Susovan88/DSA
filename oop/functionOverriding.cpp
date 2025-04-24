#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class A{
    public:
    int a_public;

    void show(){
        cout<<"a -> show function";
    };
};
class B : public A{
    public:
    int b_public;

    void show(){  // function overriding....
        cout<<"b -> show function";
    };
};
class C{
    public:
    int c_public;
};

int main(){

    B b;
    b.show();
    b.A::show();
}