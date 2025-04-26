#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
using namespace std;

string removeDuplicates(string s){
    stack<char>st;
    string newS="";
    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(s[i]!=st.top()){
            newS=newS+st.top();
            st.pop();
            st.push(s[i]);
        }
    }
    newS=newS+st.top();
    st.pop();
    return newS;
}

int main(){
    string s="aaaabccddddeefaagggghiij";
    string str=removeDuplicates(s);
    cout<<str;
}