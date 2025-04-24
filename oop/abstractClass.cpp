#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class A{ // abstract class 
    public:
    int a_public;
    // pure virtual function...
    virtual void show()=0; // declaration
    virtual void change()=0; // declaration
};
class B : public A{  
    public:
    int b_public;

    void show(){  // defination
        cout<<"b -> show function"<<endl;
    };
    void change(){  // defination
        cout<<"b -> change function"<<endl;
    };
};

int main(){

    B b;
    b.change();
    b.show();

}