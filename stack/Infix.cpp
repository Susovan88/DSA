#include <iostream>
#include <stack>
using namespace std;

int priority(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else return 2; // '*', '/'
}

int solve(int v1, int v2, char ch) {
    if (ch == '+') return v1 + v2;
    else if (ch == '-') return v1 - v2;
    else if (ch == '*') return v1 * v2;
    else return v1 / v2; // Assuming v2 != 0
}

int main() {
    string str = "(4*8)/8/(6+2)+1"; // test case
    int n = str.size();
    stack<int> val;
    stack<char> op;

    for (int i = 0; i < n; i++) {
        if (str[i]>=48 && str[i]<=57) { // if digit
            val.push(str[i] - 48); 
        } else {  // if operator
            if(op.size()==0) op.push(str[i]); // if operateor stack is empty
            else if(str[i]=='(') op.push(str[i]); // if op is -> '('
            else if (op.top()=='(') op.push(str[i]);  
            else if( str[i]==')'){    // if op is -> ")"
                while(op.top()!='('){
                    int v2 = val.top(); val.pop();
                    int v1 = val.top(); val.pop();
                    char oper = op.top(); op.pop();
                    val.push(solve(v1, v2, oper));
                }
                op.pop();
            }
            else if( priority(op.top()) < priority(str[i]))op.push(str[i]); // chech priority...
            else {   // if op is -> " + / - / * / / "
                while (!op.empty() && priority(op.top()) >= priority(str[i])) {
                    int v2 = val.top(); val.pop();
                    int v1 = val.top(); val.pop();
                    char oper = op.top(); op.pop();
                    val.push(solve(v1, v2, oper));
                }
                op.push(str[i]);
            }
        }
    }

    while (!op.empty()) {
        int v2 = val.top(); val.pop();
        int v1 = val.top(); val.pop();
        char oper = op.top(); op.pop();
        val.push(solve(v1, v2, oper));
    }

    cout << val.top() << endl;
    return 0;
}
