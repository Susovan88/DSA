#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;

string getSymboll(int n){

}

int main(){
    int num=3749;
    string str;
    int n, powerOf10=1;

    while(n!=0){
        n=(num%10)*powerOf10;
        cout<<n<<endl;
        if((n/powerOf10)==4 || (n/powerOf10)==9){ // 4 9 40 90 400 900.... 
            if((n/powerOf10)==4) str.insert(0,getSymboll(powerOf10*5));
            else str.insert(0,getSymboll(powerOf10*10));
            srt.insert(0,getSymboll(powerOf10));
        }
        else if(n<0 && n<10){

        }
        num/=10;
        powerOf10*=10;
    }

}

// 12