#include <iostream>
#include <vector>
#include <string>
using namespace std;

void pringZigZag(int n,int t){
    if(n==0) return;

    cout<<n<<" ";
    pringZigZag(n-1,t);
    cout<<n<<" ";
    pringZigZag(n-1,t);
    cout<<n<<" ";
    if(n==t) {
        cout<<endl;
        pringZigZag(n-1,t-1);

    }
}

void removeChar(string s,string str,int idx){
    if(idx==str.size()){
        cout<<"ans is "<<s<<endl;
        return;
    }
    if(str[idx]=='a'){
        removeChar(s,str,idx+1);
    }
    else removeChar(s+str[idx],str,idx+1);
}


int main(){
    // pringZigZag(4,4);
    removeChar("","asusovanPaula",0);
}
