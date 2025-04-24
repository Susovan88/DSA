#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
   
    vector<string>str = {"flower","flight","fail","flow"};
        int n=str.size();
        if(n==1) cout<< str[0];
        sort(str.begin(),str.end());
        string ans;

        for(int i=0;i<min(str[0].size(),str[n-1].size());i++){
            if(str[0][i]==str[n-1][i]){
                ans+=str[0][i];
            }
            else break;
        }

        cout<<ans<<endl;

}