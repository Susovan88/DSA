#include <iostream>
#include <string>
using namespace std;

int getSetBits(int num){
    // return __builtin_popcount(num);
    int count=0;
    while(num>0){
        num=(num & num-1);
        count++;
    }
    return count;
}

int minNumberOfFlips(int a,int b){
    int x=a^b;
    return getSetBits(x);
}

int main() {
    int a=23;
    int b=31;
    int f=minNumberOfFlips(a,b);
    cout<<f;
}