#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Display(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

vector<int> firstNegInt(vector<int>& arr, int k) {    
    int n=arr.size();
    queue<int>qu;    // store the index of negetive integer
    vector<int>ans;
        
    for(int i=0;i<n;i++){
        if(arr[i]<0)qu.push(i);
    }
    int i=0;
    while(i+k<=n){
        while(qu.size()>0 && qu.front()<i)qu.pop();
        if(qu.size()==0 || qu.front()>=i+k)ans.push_back(0);
        else ans.push_back(arr[qu.front()]);
        i++;
    }
    return ans;
}

int main(){
    vector<int>arr={9,-1,2,-4,-7,23,4,9,-1,2,-1};
    int k=3;
    Display(arr);
    vector<int>ans=firstNegInt(arr,k);
    Display(ans);
}