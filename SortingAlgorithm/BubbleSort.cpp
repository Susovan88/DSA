#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr={5,9,1,2,3,4,6,7};
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){ 
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag) break;
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}