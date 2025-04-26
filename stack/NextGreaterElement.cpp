#include <iostream>
#include <cmath> 
#include <vector>
#include <stack>
using namespace std;

vector<int> NextGreaterElemment(vector<int>& arr){ // using stack...
    stack<int>st;
    vector<int>ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--){
        while(st.size()!=0 && st.top()<=arr[i]) st.pop();
        if(st.size()!=0){
            ans[i]=st.top();
        }else ans[i]=-1;
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int>arr={12,3,17,9,2,5,10,3,1,15,8};
    vector<int>ans=NextGreaterElemment(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}