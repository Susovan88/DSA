#include <iostream>
#include <vector>
using namespace std;

bool isProssible(int minTime,vector<int>&arr,int m){
    int p=1;
    int time=0;
    for(int i=0;i<arr.size();i++){
        if(time+arr[i]<=minTime){
            time+=arr[i];
        }
        else{
            p++;
            time=arr[i];
        }
    }
    if(p<=m) return true;
    return false;
}

int minTimeToPaint(int end,int st,int p,vector<int>&arr){
    int mid,ans;
    while(st<=end){
        mid=st+(end-st)/2;
        if(isProssible(mid,arr,p)) {
            end=mid-1;
            ans=mid;
        }
        else st=mid+1;
    }
    return ans;


}

int main(){
    int m=2;
    vector<int>arr;
    arr.push_back(10);
    arr.push_back(40);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(50);
    arr.push_back(10);


    int maxEl=0,sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        maxEl=max(arr[i],maxEl);
    }

    int minTime=minTimeToPaint(sum,maxEl,m,arr);

    cout<<"minimum time take to paint : "<<minTime;

}