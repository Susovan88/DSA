#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class A{ // contain hidden vptr and vtable
    public:
    int a_public;

    virtual void show(){  // virtual function
        cout<<"a -> show function"<<endl;
    };
};
class B : public A{  // contain hidden vptr and vtable
    public:
    int b_public;

    void show(){  // overriding the virtual function
        cout<<"b -> show function"<<endl;
    };
};

int main(){
    A *a;
    a=new B; // run time binding 
    a->show();  // Calls B's show() due to runtime polymorphism

    a=new A;
    a->show();

    // A a;
    // B b;
    // cout<<sizeof(a)<<" "<<sizeof(b);
}