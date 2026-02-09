#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 56. Merge Intervals

// approch 1
vector<vector<int>> merge(vector<vector<int>>arr) {
    vector<vector<int>>ans;
    vector<int>st,end;
    for(auto ele : arr){
        st.push_back(ele[0]);
        end.push_back(ele[1]);
    }
    sort(st.begin(),st.end());
    sort(end.begin(),end.end());
    int n=st.size();
    int active=0; // currenty active intervals...
    int first=0; // start 
    int i=0,j=0;
    while(i<n && j<n){
        if(st[i]<=end[j]){
            if(active==0) first=st[i];
            active++;
            i++;
        }else{
            active--;
            if(active==0) ans.push_back({first,end[j]});
            j++;
        }
    }
    if(i==n && j<n) ans.push_back({first,end[n-1]});
    return ans;
}

// approch 2
bool cmd(vector<int>&x,vector<int>&y){
    return x[0]<y[0];
}
vector<vector<int>> merge2(vector<vector<int>>arr) {
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end(),cmd);
    ans.push_back(arr[0]);
    int i=1;
    while(i<arr.size()){
        vector<int>curr=arr[i];
        if(curr[0]<=ans[ans.size()-1][1]){ // merge this interval 
            ans[ans.size()-1][0]=min(ans[ans.size()-1][0],curr[0]);
            ans[ans.size()-1][1]=max(ans[ans.size()-1][1],curr[1]);
        }else{
            ans.push_back(curr);
        }
        i++;
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={{1,10},{2,7},{13,19},{8,12},{10,20},{21,30}};
    cout<<"approch 1"<<endl;
    vector<vector<int>>ans1=merge(arr);
    for(auto ele:ans1){
        cout<<ele[0]<<" "<<ele[1]<<endl;
    }
    cout<<"approch 2"<<endl;
    vector<vector<int>>ans2=merge(arr);
    for(auto ele:ans2){
        cout<<ele[0]<<" "<<ele[1]<<endl;
    }
}