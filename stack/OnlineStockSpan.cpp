#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// 901. Online Stock Span
class StockSpanner {
public:
    stack<pair<int,int>>st;
    int n;
    StockSpanner() {
        st.push({INT_MAX,0});
        n=0;
    }
    // using stack ->for each price try to find privious closed greater element 
    int next(int price) {
        n++;
        while(st.size()!=0 && st.top().first<=price){
            st.pop();
        }
        int val=(n-st.top().second);
        st.push({price,n});
        return val;
    }
};



int main(){
    StockSpanner st;
    int x=-1;
    while(true){
        int x;
        cin>>x;
        if(x==-1)break;
        int days=st.next(x);
        cout<<days<<endl;
    }
    return 0;
}