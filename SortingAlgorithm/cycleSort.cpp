#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int>arr={6,4,1,5,7,3,2};
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;

    int i=0;
    while(i<n){
        int currectIdx=arr[i]-1;
        if(i==currectIdx) i++;
        else swap(arr[i],arr[currectIdx]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
}