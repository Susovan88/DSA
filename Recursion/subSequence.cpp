#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// https://www.geeksforgeeks.org/problems/power-set4302/1
// Power Set
vector<string>ans;
int n;
void helper(string &s,string &temp,int idx){
    if(s.size()==idx){
        if(temp.size()!=0)ans.push_back(temp);
        return;
    }
    char ch=s[idx];
    //take
    temp.push_back(ch);
    helper(s,temp,idx+1);
    temp.pop_back();
    //skip
    helper(s,temp,idx+1);
    return;
}
vector<string> AllPossibleStrings(string s) {
    // Code here
    n=s.size();
    string temp="";
    helper(s,temp,0);
    sort(ans.begin(),ans.end());
    return ans;
}

void subsetArr(vector<vector<int>>& arr, vector<int>& v, int i, vector<int>ans,int k) {
    if (i == v.size()) {
        if(ans.size()==k) arr.push_back(ans);
        return;
    }
    if(ans.size()+(v.size()-i)<k) return;
    subsetArr(arr, v, i + 1, ans,k);

    ans.push_back(v[i]);
    subsetArr(arr, v, i + 1, ans,k);

}


int main() {

    vector<int> v = {1,2,3,4};
    vector<vector<int>> arr;
    vector<int> temp;  
    int k=3;

    subsetArr(arr, v, 0, temp,k);

    cout << "Subsets of array:\n";
    for (auto& subset : arr) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    string s = "abc";
    vector<string> ans = AllPossibleStrings(s);

    for (auto &str : ans) {
        cout << str << endl;
    }

    return 0;
}