#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// leetcode-1497
bool canArrange(vector<int>& arr, int k) {
    if(arr.size()%2!=0)return false;
    unordered_map<int,int>mp;
    int x;
    for(int i=0;i<arr.size();i++){
        x=(arr[i]%k+k)%k;
        mp[x]++;
    }
    if(mp.find(0)!=mp.end()){  // if 0 is present.
        if(mp[0]%2!=0) return false;
        mp.erase(0);
    }
    for(auto ele : mp){
        if(mp.find(k-ele.first)==mp.end()) return false;
        if(ele.second!=mp[k-ele.first]) return false;
    }
    return true;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    if (canArrange(arr, k)) {
        cout << "True (Pairing possible)" << endl;
    } else {
        cout << "False (Pairing not possible)" << endl;
    }

    return 0;
}
