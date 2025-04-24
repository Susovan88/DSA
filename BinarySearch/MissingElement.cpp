#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr = {0,1,2,3,5,6,8,9,10};
    int ans=-1; // first missing element...
    int st=0,end=arr.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==mid){
            st=mid+1;
        }
        else{
            ans=mid;
            end=mid-1;
        }
    }

    cout<<"first missing index - "<<ans;
}