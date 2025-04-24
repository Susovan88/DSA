#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

int main() {
    int n=1001;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<"False";
            break;
        }
    }
    cout<<"True";
}