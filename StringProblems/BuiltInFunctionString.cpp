#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int main(){

    string str="Susovan Paul";
    string str2="pupai";
    cout<< str.size()<<endl;
    cout<<str.length()<<endl;

    str.push_back('s');
    cout<<str<<endl;

    str.pop_back();
    str.pop_back();
    str.pop_back();
    str.pop_back();
    str.pop_back();
    cout<<str<<endl;

    str=str+str2;
    cout<<str<<endl;

    str="Hii my name is "+str;
    cout<<str<<endl;

    reverse(str.begin()+15,str.end()-6);
    cout<<str<<endl;

    // string s;
    // getline(cin,s);
    // int n=s.size();// index
    // reverse(s.begin()+0,s.begin()+(n/2));
    // cout<<s<<endl;

    // string s1;
    // cout<<"enter string:"<<endl;
    // getline(cin,s1);
    // int n=s1.size();
    // cout<< s1.substr(n/2,n);


    int x=9876523;
    string s2=to_string(x);

    cout<<"total digits are- "<< s2.size()<<endl;;

    string s3="SusoVan Paul Pupai";
    sort(s3.begin(),s3.end());

    cout<<"sorted string- "<<s3<<endl;;

    string s7="abcd";
    int g=s7.size();
    cout<<s7.substr(g/2,2);


}