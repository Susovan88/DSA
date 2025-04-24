#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Bike{
public:
    static int noOfBike; // statci member -> Its belongs to class 
    int speed;
    int price;

    // constructor overloading...
    Bike(int speed,int price){  // if we pash two parameters them call this function 
        this->speed=speed;
        this->price=price;
        cout<<"call consructor!!"<<endl;
    };
    // initilation list
    Bike(int s):speed(s),price(80){}; // if we pash one parameter them call this function 
    Bike():speed(30),price(90){};  // if we donot pass any parameter them call this function

    Bike(Bike &b){ // copy constructor // deep copy
        cout<<"copy constructor call -> deep copy."<<endl;
        speed=b.speed;
        price=b.price;
    }
    ~Bike(){
        cout<<"destructor is called!!!"<<endl;
    }

    static void increaseNoOfBike(){  // statci function -> Its belongs to class 
        noOfBike++;
    }
};

int Bike::noOfBike=9; // Define static variable outside the class
int num=988;
int main(){
    int num=90;
    cout<<num<<" "<<::num<<endl;

    Bike hero(40,70);// create object -> so this constructor is called. constructor initiliaze the peopraties of object.
    Bike honda(50);
    
    cout<<hero.price<<" "<<hero.speed<<endl;
    cout<<honda.price<<" "<<honda.speed<<endl;

    if(true){
        Bike GT();

    } // call  destructor to delete GT becouse it is out of scope.

    cout<<hero.price<<" "<<hero.speed<<endl;
    cout<<honda.price<<" "<<honda.speed<<endl;

    Bike b1(69);
    Bike b2=b1;
    Bike b3(b1); // deep copy -> call cpy consttuctor.

    b1.speed=90;
    b1.price=100;

    cout<<"b2 - "<<b2.speed<<" "<<b2.price<<endl;
    cout<<"b3 - "<<b3.speed<<" "<<b3.price<<endl;

    cout<<Bike::noOfBike<<" "<<b1.noOfBike<<" "<<b2.noOfBike<<endl;

    Bike::increaseNoOfBike();
    cout<<Bike::noOfBike<<" "<<b1.noOfBike<<" "<<b2.noOfBike<<endl;

    b1.increaseNoOfBike();
    cout<<Bike::noOfBike<<" "<<b1.noOfBike<<" "<<b2.noOfBike<<endl;

    b2.increaseNoOfBike();
    cout<<Bike::noOfBike<<" "<<b1.noOfBike<<" "<<b2.noOfBike<<endl;



}// call  destructor to delete hero, honda becouse it is out of scope.