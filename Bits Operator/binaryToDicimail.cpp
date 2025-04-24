#include <iostream>
#include <string>
using namespace std;

long long binaryToDecimal(string &binary){
    int n=binary.size();
    long long decimal=0;
    for(int i=n-1;i>=0;i--){
        char ch=binary[i];
        int num= ch-'0';
        decimal+=num*(1 << (n-i-1));
    }
    return decimal;
}

string decimalToBinary(long long num){
    string ans="";
    while(num>0){
        if(num%2==0){
            ans="0"+ans;
        }else{
            ans="1"+ans;
        }
        // num/=2;
        num=num>>1;
    }
    return ans;
}

int main() {
    string binary="0111";
    long long decimal=binaryToDecimal(binary);
    cout<<binary<< " to "<<decimal<<endl;
    
    int num=19;
    string ans=decimalToBinary(num);
    cout<<num<< " to "<<ans<<endl;
    return 0;
}
