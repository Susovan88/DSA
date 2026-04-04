#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q. Given a sorted array of non-negative distinct integers, find the smallest missing non-negative element in it.
int main(){
    vector<int> arr = {0,1,2,3,5,6,8,9,10};
    int ans=arr.size(); // first missing element...
    int st=0,end=arr.size()-1,mid;
    
    while(st<=end){
        mid=st+(end-st)/2;
        if(mid!=arr[mid] && (mid==0 ||mid-1==arr[mid-1])){
            ans=mid;
            break;
        }
        else if(mid==arr[mid]) st=mid+1;
        else {
            end=mid-1;
        }
    }
    cout<<"first missing index - "<<ans<<endl;
}