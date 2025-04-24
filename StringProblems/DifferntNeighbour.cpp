#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int main(){
    string str;
    cout<<"enter- ";
    cin>>str;
    int count=0;
    cout<<"string is - "<< str<<endl;

    for(int i=0;i<str.size();i++){
        if(str.size()==1) {
            count=0;
            break;
        }
        if(str.size()==2 && str[0]!=str[1]){
            count=1;
            break;
        }
        if(i==0) {
            if(str[i]!=str[i+1]) count++;
        }
        else if(i==str.size()-1){
            if(str[i]!=str[i-1]) count++;
        }
        else{
            if(str[i]!=str[i-1] && str[i]!=str[i+1]) count++;
        }
    }

    cout<<"diffent neighbour- "<<count;



}