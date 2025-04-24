#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class ComplexNum{
    public:
    int imaginary;
    int real;

    ComplexNum add(ComplexNum &x){
        ComplexNum y;
        y.real=x.real+this->real;
        y.imaginary=x.imaginary+this->imaginary;
        return y;
    };

    ComplexNum operator + (ComplexNum &a){  // + operator overloading...
        ComplexNum b;
        b.real=this->real+a.real;
        b.imaginary=this->imaginary+a.imaginary;
        return b;
    };

     // Declare a friend function
    friend ComplexNum operator - (ComplexNum &a,ComplexNum &b);

};

class A{
    private:
    int a_private=20;

    friend void showA_private(A &a);  // friend function
};

void showA_private(A &a){  // defination of friend function..
    cout<<"private data - "<<a.a_private<<endl;  // access private data of the class
};

// Friend function definition (outside the class)
ComplexNum operator - (ComplexNum &a,ComplexNum &b){
    ComplexNum c;
    c.real=a.real-b.real;
    c.imaginary=a.imaginary-b.imaginary;
    return c;
};

int main(){
    ComplexNum a;
    a.imaginary=9;
    a.real=20;
    ComplexNum b;
    b.real=9;
    b.imaginary=8;

    A n;
    showA_private(n);
    showA_private(n);

    ComplexNum c=a.add(b);
    cout<<"real - "<<c.real<<" imaginary- "<<c.imaginary<<endl;

    ComplexNum d=a + b; // using opearator overloading 
    cout<<"real - "<<d.real<<" imaginary- "<<d.imaginary<<endl;

    ComplexNum e=a - b; // using opearator overloading 
    cout<<"real - "<<e.real<<" imaginary- "<<e.imaginary<<endl;
}