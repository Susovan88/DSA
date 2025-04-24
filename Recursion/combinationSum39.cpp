#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void CombinationSum(vector<int>&arr,vector<int>temp,int t,int j){
    if(t==0){
        for (int i = 0; i < temp.size(); i++)
        {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(t<0){
        return;
    }

    for (int  i = j; i < arr.size(); i++){
        temp.push_back(arr[i]);
        CombinationSum(arr,temp,t-arr[i],i);
        temp.pop_back();
    }
    
}

int main(){
    vector<int>arr={2,3,5};
    vector<int>temp;
    int t=8; // target
    CombinationSum(arr,temp,t,0);
}