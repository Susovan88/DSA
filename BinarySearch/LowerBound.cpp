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
    vector<int> arr={4,6,11,12,18,30,33,34,45,65,67,89,99,100};
    int t=39;
    int st=0,end=arr.size()-1,mid;
    bool flag=false;
    // lower bound of t
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==t){
            cout<<"lower bound index is -> "<< mid<<" element -> "<<arr[mid]<<endl;
            flag=true;
            break;
        }
        else if(arr[mid]>t)end=mid-1;
        else st=mid+1;
    }
    // when the loop is break then end=<st , so end always lower bound.
    if(flag==false)cout<<"lower bound index is -> "<<end<<" element -> "<<arr[end]<<endl;

    // upper bound of t
    t=89;
    st=0,end=arr.size()-1,mid;
    flag=false;
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==t){
            flag=true;
            cout<<"lower bound index is -> "<<mid+1<<" element -> "<<arr[mid+1]<<endl;
            break;
        }else if(arr[mid]>t)end=mid-1;
        else st=mid+1;
    }

    if(flag==false)cout<<"upper bound index is -> "<<st<<" element -> "<<arr[st]<<endl;
}