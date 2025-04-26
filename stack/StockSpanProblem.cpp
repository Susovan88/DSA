#include <iostream>
#include <cmath> 
#include <vector>
#include <stack>
using namespace std;

vector<int> StockSpan(vector<int>& arr){ // using stack...
    stack<int>st;
    vector<int>ans(arr.size(),-1); // store the index of previous greater element...
    for(int i=0;i<arr.size();i++){  
        while(st.size()!=0 && arr[st.top()]<=arr[i]) st.pop();
        if(st.size()!=0){
            ans[i]=st.top();
        }else ans[i]=-1;
        st.push(i);
    }
    for(int i=0;i<ans.size();i++){ 
        ans[i]=i-ans[i];
    }
    return ans;
}

int main(){
    vector<int>arr={100,80,60,81,70,60,75,85,110};
    vector<int>ans=StockSpan(arr);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}