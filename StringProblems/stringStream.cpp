#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){

    string str="susovan is a good boy";
    stringstream ss(str);
    string temp;

    while(ss>>temp){
        cout<<temp<<endl;
    }

}