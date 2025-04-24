#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void generateBinaryString(string str,int n){
    if(str.size()==n) {
        cout<<str<<" ";
        return;
    }
    generateBinaryString(str+"0",n);
    if(str[str.size()-1]!='1') generateBinaryString(str+"1",n);
}

int main(){
    int n=3;
    generateBinaryString("",n);
}