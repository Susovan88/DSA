#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int main(){

    string s;
    cout<<"enter- ";
    cin>>s;
    int maxCount=0,count=1;
    char ch;

    // for(int i=0;i<s.size();i++){
    //     count =1;
    //     for(int j=i+1;j<s.size();j++){
    //         if(s[i]==s[j]) count++;
    //     }
    //     maxCount=max(count,maxCount);
    // }
    // cout<<"max count is - "<<maxCount<<endl;
    // for(int i=0;i<s.size();i++){
    //     count =1;
    //     ch=s[i];
    //     for(int j=i+1;j<s.size();j++){
    //         if(s[i]==s[j]) count++;
    //     }
    //     if(count==maxCount) cout<<ch<<" - "<<maxCount<<endl;
    // }



    // // easy method...
    vector<int>arr(26,0);
    for(int i=0;i<s.size();i++){
        int ch=s[i];
        int ascii=(int)ch;
        arr[ascii-97]+=1;
    }
    
    for(int i=0;i<arr.size();i++){
        maxCount=max(maxCount,arr[i]);
    }
    cout<<"max count - "<<maxCount<<endl;

    for(int i=0;i<arr.size();i++){
        if(maxCount==arr[i]){
            cout<<"character is - "<<(char)(i+97)<<endl;
        }
    }
}