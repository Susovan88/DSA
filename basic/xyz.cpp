#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,int>mp;
    unordered_set<int>st;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]=i;
        st.insert(arr[i]);
        cout<<arr[i]<<" ";
    }
    reverse(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // string str;
    // cin>>str;
    // cout<<str<<" ";
    // for(char ch : str){
    //     cout<<ch-'a'<<" "<<ch<<endl;
    // }
    // int sn;
    // cin>>sn;
    // vector<string>s;
    // for(int i=0;i<sn;i++){
    //     string t;
    //     cin>>t;
    //     s.push_back(t);
    //     cout<<t<<" ";
    // }
    // cout<<endl;
    // sort(s.begin(),s.end());
    // for(auto ele : s){
    //     cout<<ele<<" ";
    // }
    for(auto ele : mp){
        cout<<ele.first<<"-"<<ele.second<<" ";
    }
    cout<<endl;
    int y;
    cin>>y;
    if(mp.find(y)!=mp.end())cout<<"exist"<<endl;
    else cout<<" not exist"<<endl;
    return 0;
}













// #include <bits/stdc++.h>