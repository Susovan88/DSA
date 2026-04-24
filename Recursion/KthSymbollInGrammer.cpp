#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 779. K-th Symbol in Grammar
int getKthSymbol(int s,int n,int k){
    if(n==1)return s;
    int mid=pow(2,(n-1))/2; 
    if(k<=mid){ // left
        if(s==0) return getKthSymbol(0,n-1,k);
        else return getKthSymbol(1,n-1,k);
    }else{// right
        if(s==1) return getKthSymbol(0,n-1,k-mid);
        else return getKthSymbol(1,n-1,k-mid);
    }
}
int kthGrammar(int n, int k) {
    return getKthSymbol(0,n,k);
}
string ans="";
void helper(int &n,string temp){ // Time Limit Exceeded
    if(temp.size()==pow(2,(n-1))){
        ans=temp;
        return;
    }
    string str="";
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='0'){
            str.push_back('0');
            str.push_back('1');
        }else{
            str.push_back('1');
            str.push_back('0');     
        }
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    helper(n,str);
    return;
}
int kthGrammar1(int n, int k) {
    helper(n,"0");
    cout<<ans;
    return ans[k-1]-48;
}

int main(){
    int n=13;
    int k=14;
    cout<<kthGrammar(n,k);
}