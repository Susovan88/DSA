#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 2187. Minimum Time to Complete Trips
long long minimumTime(vector<int>& time, int totTps) {
    int n=time.size();
    if(n==1) return (long long)totTps*time[0];
    long long mnE=LLONG_MAX;
    long long mxE=LLONG_MIN;
    for(int i=0;i<n;i++){
        mnE = min(mnE, (long long)time[i]);
        mxE = max(mxE, (long long)time[i]);
    }
    long long st=mnE,end=(long long)mxE*totTps;

    while(st<=end){
        long long mid=st+(end-st)/2;
        long long cTps=0; // completed trips
        for(int i=0;i<n;i++){
            long long tps=mid/time[i];
            cTps+=tps;
            if(cTps>=totTps)break;
        }
        cout<<st<<" - "<<end<<" => "<<mid<<" - "<<cTps<<endl;
        if(cTps>=totTps)end=mid-1;
        else st=mid+1;
    }
    return st;
}

int main(){
    vector<int>time={3324,5249,8558,6329,2222,6901,1126,6795,3374,2908,8773,9017,6792,6882,6921,7182,6294,9418};
    int totalTrips=82355;
    int k=minimumTime(time,totalTrips);
    cout<<"Minimum Time to Complete Trips is -> "<<k<<endl;
}