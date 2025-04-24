#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){

    vector<string>str={"9809","00909","000010","0020912","0909","00100"};
    int maxNum=stoi(str[0]);
    string s=str[0];
    for(int i=1;i<str.size();i++){
        if(maxNum<stoi(str[i])){
            maxNum=stoi(str[i]);
            s=str[i];
        }
    }

    cout<<" max num- " <<s;




}