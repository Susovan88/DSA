#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

// Max Number of K-Sum Pairs
int maxOperations(vector<int>& nums, int k) {
    int count=0;
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        if(mp.size()!=0 && mp.find(nums[i])!=mp.end()){
            count++;
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
        }else{
            mp[k-nums[i]]++;
        }
    }
    return count;
}

//  Relative Sort Array
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int,int>mp;
    for(int i=0;i<arr1.size();i++){
        mp[arr1[i]]++;
    }

    int idx=0;int a;
    for(int i=0;i<arr2.size();i++){
        a=mp[arr2[i]];
        mp.erase(arr2[i]);
        for(int j=idx;j<idx+a;j++){
            arr1[j]=arr2[i];
        }
        idx=idx+a;
    }

    int midIdx=idx;
    for(auto el : mp){
        a=el.second;
        for(int j=idx;j<idx+a;j++){
            arr1[j]=el.first;
        }
        idx=idx+a;
    }

    sort(arr1.begin()+midIdx,arr1.end());

    return arr1;
}

int main() {
    // -------- Max Number of K-Sum Pairs --------
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;

    cout << "Max K-Sum Pairs: " << maxOperations(nums, k) << endl;

    // -------- Relative Sort Array --------
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> result = relativeSortArray(arr1, arr2);

    cout << "Relative Sorted Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
