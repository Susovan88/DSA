#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 253 Meeting Rooms 2
int meeingRoom(vector<vector<int>>arr){
    int ans=0;
    int rooms=0;
    vector<int>st,end;
    for(auto ele : arr){
        st.push_back(ele[0]);
        end.push_back(ele[1]);
    }
    sort(st.begin(),st.end());
    sort(end.begin(),end.end());
    int n=st.size();
    int i=0,j=0;
    while(i<n){
        if(st[i]<end[j]){
            rooms++;
            ans=max(ans,rooms);
            i++;
        }else if(st[i]==end[j]){
            i++;j++;
        }else{
            rooms--;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={{1,10},{2,7},{3,19},{8,12},{10,20},{11,30}};
    cout<<meeingRoom(arr);
}