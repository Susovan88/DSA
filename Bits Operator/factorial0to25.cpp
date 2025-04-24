#include <iostream>
#include <climits> 
#include <string>
#include <vector>
using namespace std;

int main() {
    int n=25;
    vector<long long int>ans(n+1,1);
    int mod=1000000000+7;
    for(int i=1;i<ans.size();i++){
        ans[i]=((i%mod)*(ans[i-1]%mod))%mod;
    }

    for(int i=0;i<ans.size();i++){
        cout<<i<<" : "<<ans[i]<<endl;
    }

}