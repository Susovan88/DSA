#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int countQuadruplets2(vector<int>& nums) { // O(n^4)
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum=nums[i]+nums[j]+nums[k];
                for(int l=k+1;l<n;l++){
                    if(sum==nums[l])count++;
                }
            }
        }
    }
    return count;
}

// 1995. Count Special Quadruplets
int countQuadruplets(vector<int>& nums) { // -> O(n^2)
    unordered_map<int,int>mp; // < (nums[d] - nums[c]) , freq of (nums[d] - nums[c]) >
    int n=nums.size();
    
    // nums[a] + nums[b] + nums[c] == nums[d] 
    // convert into => nums[a] + nums[b] == nums[d] - nums[c]

    int count=0;
    for(int b=n-3;b>=1;b--){
        for(int d=b+2;d<n;d++){
            int c=b+1;
            mp[nums[d]-nums[c]]++;
        }
        for(int a=0;a<b;a++){
            int sum=nums[a]+nums[b];
            if(mp.find(sum)!=mp.end())count+=mp[sum];
        }
    }

    return count;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    cout<<countQuadruplets(arr);
}