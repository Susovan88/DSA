#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 216. Combination Sum III
vector<vector<int>>ans;
void helper(vector<int>&temp,int idx,int sum,int &k){
    if(temp.size()==k){
        if(sum==0)ans.push_back(temp);
        return;
    }
    if(idx==10)return;
    if(sum>=idx){
        temp.push_back(idx);
        helper(temp,idx+1,sum-idx,k);
        temp.pop_back();
    }
    helper(temp,idx+1,sum,k);
    return;
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>temp;
    helper(temp,1,n,k);
    return ans;
}

int main(){
    int k=5;
    int n=18;
    combinationSum3(k,n);
    for(auto ele : ans){
        for(auto val : ele)cout<<val<<" ";
        cout<<endl;
    }
}