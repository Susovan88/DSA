#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

int main() {
    int n=49;
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    for(int i=sqrt(n);i>=1;i--){
        if(n%i==0){
            cout<<n/i<<" ";
        }
    }
}