#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int arr[]={1, 2, 3, 3, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool flag=false;

    for(int i=1;i<n;i++){ // prefix sum
        arr[i]+=arr[i-1];
    }

    for(int i=0;i<n;i++){
        if(2*arr[i]==arr[n-1]){
            flag=true;
            break;
        }
    }

    cout<<flag;

}