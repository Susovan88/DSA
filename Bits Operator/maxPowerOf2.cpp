#include <iostream>
#include <string>
using namespace std;

int maxPowerOf2(int num){
    int temp;
    while(num>0){
        temp=num;
        num=(num & num-1);
    }
    return temp;
}

int maxPowerOf2M1(int n){
    n=n | (n>>1);
    n=n | (n>>2);
    n=n | (n>>4);
    n=n | (n>>8);
    n= n | (n>>16);
    return (n+1)>>1;
}

int main() {
    int num=1029;
    int a=maxPowerOf2(num);
    int b= maxPowerOf2M1(num);
    cout<<a<<"  "<<b;
}