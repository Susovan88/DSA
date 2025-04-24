#include <iostream>
#include <vector>
using namespace std;

void PrintNto1(int a){
    if(a==0) return;
    cout<< a<<endl;
    PrintNto1(a-1);
}

int sumNto1(int n){
    if(n==0) return 0;
    return n+sumNto1(n-1);
}

void Print1toN(int a){
    if(a==0) return;
    PrintNto1(a-1);
    cout<< a <<endl;
}

int power(int a,int b){
    if(a==0) return 0;
    if(a==0 && b==0 ) return 0;
    if(b==0 ) return 1;
    if(b==1) return a;

    return a* power(a,b-1);
}

int main(){
    int a;
    cin>>a;
    // PrintNto1(a);
    // Print1toN(a);
    cout<<sumNto1(a)<<endl;
    cout<<power(3,5);
}