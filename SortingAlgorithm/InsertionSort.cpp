#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr={1,0,5,9,10,-3,2,8,13,-4,6,7};
    int n=arr.size();
    
    int idx;
    for(int i=1;i<n;i++){
        for(int j=i;j>=1;j--){
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
            else break;
        }
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}