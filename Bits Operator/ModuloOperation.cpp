#include <iostream>
#include <climits> 
#include <string>
using namespace std;

int main() {
    int a = INT_MAX;
    cout<<a<<endl;
    cout<<a%3<<endl;
    int b=10;
    cout<<(a%3+b%3)%3<<endl;
}