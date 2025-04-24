#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Student {
    public:
    string name;
    int roll;
    int age;

    Student(string name,int roll,int age){
        this->name=name;
        this->roll=roll;
        this->age=age;
    };
};

void change(Student *s){
    s->age=22;
}

int main(){
    Student Pupai("susovan",8,21);
    cout<<Pupai.age<<endl;
    Student *s1;
    s1=&Pupai;
    cout<<s1->age<<endl;
    Student *s2=new Student("taniya",7,20);
    cout<<s2->age<<endl;
    change(s2); // parameter is pointer of student
    cout<<s2->age;
}