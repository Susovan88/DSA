#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr={5,9,1,2,8,3,4,6,7};
    int n=arr.size();
    
    int minIdx;
    for(int i=0;i<n-1;i++){
        minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]) minIdx=j;
        }
        swap(arr[i],arr[minIdx]);
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}