#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

    return 0;
}