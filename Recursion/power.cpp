#include <iostream>
#include <vector>
using namespace std;

int powerM1(int a,int b){
    if(a==0) return 0;
    if(a==0 && b==0 ) return 0;
    if(b==0 ) return 1;
    if(b==1) return a;

    return a* powerM1(a,b-1);
}

int powerM2(int a,int b){
    if(a==0) return 0;
    if(a==0 && b==0 ) return 0;
    if(b==0 ) return 1;
    if(b==1) return a;

    int ans=powerM2(a,b/2);
    if(b%2==0) {
        return ans* ans;
    }
    else {
        return a * ans * ans;
    }
}


int main(){
    cout<<powerM2(3,6);
}