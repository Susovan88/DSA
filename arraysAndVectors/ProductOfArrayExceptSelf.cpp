#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// 238. Product of Array Except Self
vector<int> productExceptSelf2(vector<int> nums) {
    int n=nums.size();
    vector<int>pre(n);
    vector<int>suf(n);
    pre[0]=1;
    for(int i=1;i<n;i++){ // prefix
        pre[i]=pre[i-1]*nums[i-1];
    }
    suf[n-1]=1;
    for(int i=n-2;i>=0;i--){ // sufix
        suf[i]=suf[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++){   // -> prefix[i]* sufix[i]
        nums[i]=suf[i]*pre[i];
        cout<<pre[i]<<" - "<<suf[i]<<endl;
    }
    cout<<endl;
    return nums;
}


vector<int> productExceptSelf(vector<int> nums) {
    int n=nums.size();
    int pro=1;
    int isZ=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            isZ++;
            continue;
        }
        pro*=nums[i];
    }
    for(int i=0;i<n;i++){
        if((isZ>0 && nums[i]!=0) || (isZ>1 && nums[i]==0)){
            nums[i]=0;
        }
        else if(isZ==1 && nums[i]==0)nums[i]=pro;
        else nums[i]=pro/nums[i];
    }
    return nums;
}


int main(){
    vector<int>arr={3,2,12,-9,7,0,6,-7,4,5,-5,-12};
    vector<int>ans=productExceptSelf2(arr);
    for(auto ele : ans)cout<<ele<<" ";

    cout<<endl;
    vector<int>ans2=productExceptSelf(arr);
    for(auto ele : ans2)cout<<ele<<" ";
}