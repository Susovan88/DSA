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

int main() {
    int num=22;
    int setBits=getSetBits(num);
    cout<<setBits;
}