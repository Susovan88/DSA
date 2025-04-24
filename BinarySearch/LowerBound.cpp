#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr={4,6,12,34,43,54,66,70,88,90};
    int t=80;
    int st=0,end=arr.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==t) cout<<mid;
        else if(arr[mid]<t) st=mid+1;
        else end=mid-1;
    }
    cout<<arr[st-1];
    
}