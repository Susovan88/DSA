#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

void printArr(vector<int>v,int n){
    if(n==v.size()) return;
    cout<<v[n]<<" ";
    printArr(v,n+1);
}

void maxValue(vector<int>v,int n,int m){
    if(n==v.size()) {
        cout<<"max value - "<<m;
        return;
    }
    if(v[n]>m) m=v[n];
    maxValue(v,n+1,m);
}

int storeMaxVal(vector<int>v,int n){
    if(n==v.size()) return INT_MIN;
    return max(v[n],storeMaxVal(v,n+1));
}

int main(){
    vector<int>v={9,8,2,4,23,12,67,7,12,13};
    printArr(v,0);
    maxValue(v,0,INT_MIN);

    cout<<endl<<storeMaxVal(v,0);

}