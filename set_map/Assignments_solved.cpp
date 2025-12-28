#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// Q1. 1865. Finding Pairs With a Certain Sum

class FindSumPairs {
public:
    vector<int>nums1,nums2;
    unordered_map<int,int>mp1,mp2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;

        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp2[nums2[index]+val]++;
        mp2[nums2[index]]--;
        nums2[index]+=val;

    }
    
    int count(int tot) {
        int count=0;
        for(auto ele : mp1){
            if(mp2.find(tot-ele.first)!=mp2.end()){
                count+=(ele.second*mp2[tot-ele.first]);
            }
        }
        return count;

    }
};


/*
Q2. Given an array of names of candidates in an election. A candidate’s name in the array represents a vote
cast on the candidate. Print the name of candidates who received the maximum vote. If there is a tie, print a
lexicographically smaller name.
*/
vector<string> winner(string arr[], int n) {
    // Return the string containing the name and an integer
    // representing the number of votes the winning candidate got
    
    unordered_map<string,int>mp;
    int max_vot=0;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        max_vot=max(max_vot,mp[arr[i]]);
    }
    stack<string>st;
    for(auto ele : mp){
        if(ele.second==max_vot){
            st.push(ele.first);
        }
    }
    string str;
    while(st.size()>1){
        str=st.top();st.pop();
        if(str<st.top()){
            st.pop();
            st.push(str);
        }
    }
    vector<string>winner;
    winner.push_back(st.top());
    winner.push_back(to_string(mp[st.top()]));
    
    return winner;
}

// Q3. -> Group Anagrams, leetcode - 49
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>mp;
    vector<vector<string>>ans;
    string lexo="";
    for(int i=0;i<strs.size();i++){
        lexo=strs[i];
        sort(lexo.begin(),lexo.end());
        if(mp.find(lexo)!=mp.end()){
            mp[lexo].push_back(strs[i]);
        }else {
            vector<string>str;
            str.push_back(strs[i]);
            mp[lexo]=str;
        }
    }
    for(auto ele:mp){
        ans.push_back(ele.second);
    }
    return ans;
}




// Q4. Count nice pairs in an array (Leetcode :-1814)
int rev(int num){
    int a=num;
    int rev_num=0;
    while(num!=0){
        a=num%10;
        num/=10;
        rev_num*=10;
        rev_num+=a;
    }
    return rev_num;
}

int countNicePairs(vector<int>& nums) {
    unordered_map<int,int>mp;
    int count=0;
    int n;

    for(int i=0;i<nums.size();i++){
        n=nums[i]-rev(nums[i]);
        if(mp.find(n)!=mp.end()){
            count=count%1000000007;
            count+=mp[n];
        }
        mp[n]++;
    }

    return count%1000000007;
    
}


int main() {

    // q1.  
    vector<int> nums1 = {1, 1, 2, 2, 2};
    vector<int> nums2 = {1, 2, 3, 4, 5};

    FindSumPairs obj(nums1, nums2);

    cout << obj.count(7) << endl;   // Expected: 8

    obj.add(3, 2);                  // nums2[3] = 4 + 2 = 6

    cout << obj.count(8) << endl;   // Expected: 2

    // Test Q2
    string votes[] = {"john", "john", "jack", "jack", "jack", "john"};
    int n = 6;

    vector<string> res = winner(votes, n);
    cout << "Winner: " << res[0] << endl;
    cout << "Votes: " << res[1] << endl;

    cout << endl;

    // Test Q4
    vector<int> nums = {42, 11, 1, 97};
    cout << "Nice Pairs Count: " << countNicePairs(nums) << endl;

    // test Q3
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    for (auto &group : result) {
        cout << "[ ";
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}


