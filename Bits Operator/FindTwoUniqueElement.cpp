#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[]={1,3,2,1,3,5,2,4,9,4};
    int n=10;
    int res=0;
    int a=0,b=0;

    // xor of every elemnt
    for(int i=0;i<n;i++){
        res^=arr[i];
    }
    int temp=res;
    int k=0;

    // search which bit is 1 of res from lsb
    while (true){
        if((temp & 1)==1){
            break;
        }
        temp=temp>>1;
        k++;
    }

    // which element of kth bit 1, xor them...
    for(int i=0;i<n;i++){
        if(((arr[i]>>k)&1)==1){
            a^=arr[i];
        }
    }
    b= res ^ a;

    cout<<a<<"  "<<b;
}