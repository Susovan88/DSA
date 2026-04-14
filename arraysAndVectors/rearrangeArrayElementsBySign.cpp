#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 2149. Rearrange Array Elements by Sign
vector<int> rearrangeArray(vector<int>& arr) {   
    int n=arr.size();
    vector<int>ans(n);
    int i=0,j=1;
    for(int k=0;k<n;k++){
        if(arr[k]<0){
            ans[j]=arr[k];
            j+=2;
        }else{
            ans[i]=arr[k];
            i+=2;
        }
    }
    return ans;
}


int main(){
    vector<int>arr={1,-2,3,4,5,-9,-8,7,-10,11,91,-81,-12,-78};
    vector<int>ans=rearrangeArray(arr);
    for(auto ele : ans)cout<<ele<<" ";
}