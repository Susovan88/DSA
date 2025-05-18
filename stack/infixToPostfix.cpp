#include <iostream>
#include <stack>
using namespace std;

int priority(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else return 2; // '*', '/'
}

string solve(string v1, string v2, char ch) {
    string s="";
    s+=v1;
    s+=v2;
    s.push_back(ch);
    return s;
}

int main(){
    string str = "4+(8*2)/4-(9+1)-8+(1*3)"; // test case
    int n = str.size();
    stack<string> val;
    stack<char> op;
    for(int i=0;i<n;i++){
        if(str[i]>=48 && str[i]<=57) val.push(to_string(str[i]-48));
        else {
            if(op.size()==0) op.push(str[i]); // if operateor stack is empty
            else if(str[i]=='(') op.push(str[i]); // if op is -> '('
            else if (op.top()=='(') op.push(str[i]);  
            else if( str[i]==')'){    // if op is -> ")"
                while(op.top()!='('){
                    string v2=val.top();val.pop();
                    string v1=val.top();val.pop();
                    char ch =op.top();op.pop();
                    val.push(solve(v1,v2,ch));
                }
                op.pop();   // remove  '('
            }
            else if(priority(op.top())<priority(str[i])) op.push(str[i]);
            else{
                while( op.size()!=0 && priority(op.top())>=priority(str[i])){
                    string v2=val.top();val.pop();
                    string v1=val.top();val.pop();
                    char ch =op.top();op.pop();
                    val.push(solve(v1,v2,ch));
                }
                op.push(str[i]);
            }
        }
    }
    while(op.size()!=0){
        string v2=val.top();val.pop();
        string v1=val.top();val.pop();
        char ch =op.top();op.pop();
        val.push(solve(v1,v2,ch));
    }
    cout<<val.top();
}