#include <iostream>
#include <vector>
#include <climits> 
#include <string> 
using namespace std;

// 22. Generate Parentheses
vector<string>ans;
int tb;
void helper(int ob,int cb,string &temp){
    if(ob==tb && cb==tb){
        ans.push_back(temp);
        return;
    }
    if(ob<tb){
        temp.push_back('(');
        helper(ob+1,cb,temp);
        temp.pop_back();
    }
    if(cb<ob){
        temp.push_back(')');
        helper(ob,cb+1,temp);
        temp.pop_back();
    }
    return;
}
vector<string> generateParenthesis(int n) {
    tb=n;
    string temp="";
    helper(0,0,temp);
    return ans;
}

int main(){
    int n=5;
    generateParenthesis(n);
    for(auto ele : ans)cout<<ele<<endl;
}