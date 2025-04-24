#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){

    string str="susovan is a good boy. he is a good DSA student. a";
    stringstream ss(str);
    string temp;
    vector<string>v;
    int c=1,maxCount=0;

    while(ss>>temp){
        // cout<<temp<<endl;
        v.push_back(temp);
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) c++;
        else {
            maxCount=max(maxCount,c);
             c=1;
        }
    }

    cout<<"max count is - "<<maxCount<<endl;

    c=1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) {
            c++;
            if(c==maxCount) cout<<v[i]<< " maxcount - "<< maxCount<<endl;
        }else{
             c=1;
        }
    }



}