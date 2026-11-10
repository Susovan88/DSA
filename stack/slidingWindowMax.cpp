#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// //  // //  239. Sliding Window Maximum

// Using priority_queue
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    int n=nums.size();
    priority_queue<pair<int,int>>pq;
    vector<int>ans;
    int i=0;
    int j=0;
    while(j<k){
        pq.push({nums[j],j});
        j++;
    }
    ans.push_back(pq.top().first);
    while(j<n){
        pq.push({nums[j],j});
        while(pq.top().second<=i)pq.pop();
        ans.push_back(pq.top().first);
        i++;
        j++;
    }
    return ans;
}

// Using deque
vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
    int n=nums.size();
    deque<int>dq;
    vector<int>ans;
    int j=0;
    while(j<n){
        while(dq.size()!=0 && dq.front()<=(j-k))dq.pop_front();
        while(dq.size()!=0 && nums[dq.back()]<nums[j])dq.pop_back();
        dq.push_back(j);
        if(j>=k-1)ans.push_back(nums[dq.front()]);
        j++;
    }
    return ans;
}

// // using stack...
vector<int> maxSlidingWindow3(vector<int>& nums, int k) {
    if(k==1) return nums;
    int n=nums.size();
    vector<int>nge(n,n);  // next greater element
    vector<int>ans;
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(st.size()!=0 && nums[st.top()]<nums[i])st.pop();
        if(st.size()!=0)nge[i]=st.top();
        st.push(i);
    }
    int mx=INT_MIN;
    int j=0;
    for(int i=0;i<n-k+1;i++){
        if(j<i)j=i;
        while(nge[j]<i+k)j=nge[j];
        ans.push_back(nums[j]);
    }
    return ans;
}


int main(){
    vector<int>arr={1,8,7,56,1,3,5,678,88,13,45,78,6,121,54,398,34,2,1,3,68,123,1,24};
    int k=4;
    vector<int>ans=maxSlidingWindow1(arr,k);
    for(auto ele : ans)cout<<ele<<" ";
}
