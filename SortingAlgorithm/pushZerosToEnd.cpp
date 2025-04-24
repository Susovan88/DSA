#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr={5,9,0,8,0,1,0,2,0,0,3};   // ans=> 5 9 8 1 2 3 0 0 0 0 0
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]==0 && arr[j+1]!=0) {
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag) break;
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}