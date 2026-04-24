#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1
vector<string>ans;
int n;
void helper(string s,string &temp){
    if(temp.size()==n){
        ans.push_back(temp);
        // cout<<temp<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        temp.push_back(s[i]);
        string rem=s.substr(0,i)+s.substr(i+1);
        helper(rem,temp);
        temp.pop_back();
    }
    return;
}
vector<string> permutation(string S) {
    // Your code here
    n=S.size();
    string temp;
    helper(S,temp);
    sort(ans.begin(),ans.end());
    return ans;
}

void permutationOfStr(string ans,string str){
    if(str==""){
        cout<<ans<<" ";
        return;
    }
    for(int i=0;i<str.size();i++){
        string temp=str.substr(0,i)+str.substr(i+1);
        permutationOfStr(ans+str[i],temp);
    }
}


int main(){
    string str="abcd";
    // permutationOfStr("",str);
    permutation(str);
    for(auto ele : ans)cout<<ele<<endl;
}