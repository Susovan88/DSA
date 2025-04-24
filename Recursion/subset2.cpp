#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void subset(string subS, int i, string& str, vector<string>& ans,bool flag) {
    if (i == str.length()) {
        ans.push_back(subS);
        return;
    }
    if(i==str.size()-1){
        if(flag) subset(subS + str[i], i + 1, str, ans,true);
        subset(subS, i + 1, str, ans,true);
        return;
    }
    if(str[i]==str[i+1]){
        if(flag) subset(subS + str[i], i + 1, str, ans,true);
        subset(subS, i + 1, str, ans,false);
    }else{
        if(flag) subset(subS + str[i], i + 1, str, ans,true);
        subset(subS, i + 1, str, ans,true);
    }
}

void printArr(vector<string>& v, int n) {
    if (n == v.size()) return;
    cout << v[n] << endl;
    printArr(v, n + 1);
}

void subsetArr(vector<vector<int>>& arr, vector<int>& v, int i, vector<int>ans) {
    if (i == v.size()) {
        arr.push_back(ans);
        return;
    }

    subsetArr(arr, v, i + 1, ans);

    ans.push_back(v[i]);
    subsetArr(arr, v, i + 1, ans);

}

int main() {
    string s = "aba";
    sort(s.begin(),s.end());
    vector<string> ans;
    subset("", 0, s, ans,true);

    printArr(ans, 0);

    // vector<int> v = {1, 2, 3};
    // vector<vector<int>> arr;
    // vector<int> temp;  

    // subsetArr(arr, v, 0, temp);

    // cout << "Subsets of array:\n";
    // for (auto& subset : arr) {
    //     cout << "{ ";
    //     for (int num : subset) {
    //         cout << num << " ";
    //     }
    //     cout << "}\n";
    // }

    return 0;
}
