#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int main(){

    string s="physicwallah",t="wpahlyaihcls";
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    cout<<s<<endl<<t<<endl;

    if(s==t) cout<<"true";
    else cout<<"false";

}