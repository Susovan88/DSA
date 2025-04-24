#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void subArray(vector<vector<int>>&ans,vector<int>&arr,int idx,vector<int>temp){
    if(idx==arr.size()){
        ans.push_back(temp);
        return;
    }
    subArray(ans,arr,idx+1,temp);
    if(temp.size()==0 || temp[temp.size()-1]==arr[idx-1]){
        temp.push_back(arr[idx]);
        subArray(ans,arr,idx+1,temp);
    }
}


int main(){
    vector<int>arr={1,2,3,4};
    vector<int>temp;
    vector<vector<int>>ans;
    subArray(ans,arr,0,temp);

    cout << "subArray of array:\n";
    for (auto& subset : ans) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
}