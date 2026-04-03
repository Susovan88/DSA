#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
✅ Lower Bound
👉 First position where value is ≥ target

✅ Upper Bound
👉 First position where value is > target
*/
int main(){
    vector<int> arr={4,6,12,34,34,34,34,43,54,54,54,54,70,70,88,90,100};
    int t=34;
    int st=0,end=arr.size(),mid;

    // lower bound of t
    while(st<end){
        mid=st+(end-st)/2;
        if(arr[mid]>=t)end=mid;
        else st=mid+1;
    }
    cout<<"lower bound index is -> "<<st<<endl;

    // upper bound of t
    st=0,end=arr.size(),mid;
    while(st<end){
        mid=st+(end-st)/2;
        if(arr[mid]<=t)st=mid+1;
        else end=mid;
    }
    cout<<"upper bound index is -> "<<end<<" "<<arr[end]<<endl;
}