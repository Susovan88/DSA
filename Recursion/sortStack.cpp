// #include<iostream>
// #include <bits/stdc++.h>
// using namespace std;

// //
// void sortStack(stack<int> &st) {
//     map<int,int>mp;
//     while(st.size()!=0){
//         int t=st.top();
//         st.pop();
//         mp[t]++;
//     }
    
//     for(auto ele : mp){
//         int x=ele.second;
//         while(x--)st.push(ele.first);
//     }
// }

// int main(){
//     stack<int>st;
//     st.push(12);
//     st.push(22);
//     st.push(2);
//     st.push(5);
//     st.push(7);
//     st.push(3);
//     st.push(16);
//     sortStack(st);
    
//         while(st.size()!=0){
//         int t=st.top();
//         st.pop();
//         cout<<t<<" ";
//     }
// }