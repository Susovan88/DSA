#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}


int main(){
    int a,b;
    cout<<"enter a and b (b>a):";
    cin>>a;
    cin>>b;

    cout<<gcd(a,b);
}