#include<iostream>
#include<vector>
#include<list>
using namespace std;


int main(){

    vector<int> arr={5,6,2,6,9,12,0};

    // vector<int>::iterator it;
    // for(it=arr.begin();it!=arr.end();it++){
    //     cout<<*(it)<<" ";
    // }
    // cout<<endl;

    vector<int>::reverse_iterator it;
    for(it=arr.rbegin();it!=arr.rend();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
}
