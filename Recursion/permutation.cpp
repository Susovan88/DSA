#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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
    permutationOfStr("",str);
}