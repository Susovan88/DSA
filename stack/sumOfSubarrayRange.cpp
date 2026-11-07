#include <iostream>
#include <cmath> 
#include <vector>
#include <stack>
using namespace std;

int n;
void rightRange(vector<int>&arr,vector<int>&rgr){
    stack<pair<int,int>>st;
    st.push({0,arr[0]});
    for(int i=1;i<n;i++){
        while(st.size()!=0){
            if(arr[i]<=st.top().second){
                auto ele=st.top();
                st.pop();
                rgr[ele.first]=i-1;
            }else break;
        }
        st.push({i,arr[i]});
    }
    while(st.size()!=0){
        auto ele=st.top();
        st.pop();
        rgr[ele.first]=n-1;
    }
}

void leftRange(vector<int>&arr,vector<int>&lfr){
    stack<pair<int,int>>st;
    st.push({n-1,arr[n-1]});
    for(int i=n-2;i>=0;i--){
        while(st.size()!=0){
            if(arr[i]<st.top().second){
                auto ele=st.top();
                st.pop();
                lfr[ele.first]=i+1;
            }else break;
        }
        st.push({i,arr[i]});
    }
    while(st.size()!=0){
        auto ele=st.top();
        st.pop();
        lfr[ele.first]=0;
    }
}

long long sumSubarrayMins(vector<int>& arr) {
    n=arr.size();
    vector<int>lfr(n);
    vector<int>rgr(n);
    leftRange(arr,lfr);
    rightRange(arr,rgr);
    long long count=0;
    for(int i=0;i<n;i++){
        int lf=i-lfr[i]+1;
        int rg=rgr[i]-i+1;
        count=(count+(lf*rg*1LL*arr[i]));
    }
    return count;
}

void rightRangeMx(vector<int>&arr,vector<int>&rgr){
    stack<pair<int,int>>st;
    st.push({0,arr[0]});
    for(int i=1;i<n;i++){
        while(st.size()!=0){
            if(arr[i]>=st.top().second){
                auto ele=st.top();
                st.pop();
                rgr[ele.first]=i-1;
            }else break;
        }
        st.push({i,arr[i]});
    }
    while(st.size()!=0){
        auto ele=st.top();
        st.pop();
        rgr[ele.first]=n-1;
    }
}

void leftRangeMx(vector<int>&arr,vector<int>&lfr){
    stack<pair<int,int>>st;
    st.push({n-1,arr[n-1]});
    for(int i=n-2;i>=0;i--){
        while(st.size()!=0){
            if(arr[i]>st.top().second){
                auto ele=st.top();
                st.pop();
                lfr[ele.first]=i+1;
            }else break;
        }
        st.push({i,arr[i]});
    }
    while(st.size()!=0){
        auto ele=st.top();
        st.pop();
        lfr[ele.first]=0;
    }
}

long long sumSubarrayMaxs(vector<int>& arr) {
    n=arr.size();
    vector<int>lfr(n);
    vector<int>rgr(n);
    leftRangeMx(arr,lfr);
    rightRangeMx(arr,rgr);
    long long count=0;
    for(int i=0;i<n;i++){
        int lf=i-lfr[i]+1;
        int rg=rgr[i]-i+1;
        count=(count+(lf*rg*1LL*arr[i]));
    }
    return count;
}

long long subArrayRanges(vector<int>& nums) {
    return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
}


int main(){
    vector<int>arr={5,6,1,3,4,8,1,7,3,1,9};
    cout<<subArrayRanges(arr);
}