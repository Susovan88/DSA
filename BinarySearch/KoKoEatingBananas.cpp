#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 875. Koko Eating Bananas
int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
    if(n==1){
        if(piles[0]%h==0) return piles[0]/h;
        return (piles[0]/h)+1;
    }
    int mxE=INT_MIN;
    for(int i=0;i<n;i++){
        mxE=max(mxE,piles[i]);
    }
    long long st=1,end=mxE;
    while(st<=end){
        long long mid=st+(end-st)/2; // k 
        long long tH=0; // total hour
        for(int i=0;i<n;i++){
            long long nH=piles[i]/mid; // need hour for piles[i]
            if(piles[i]%mid!=0)nH++;
            tH+=nH;
            if(tH>h)break;
        }
        cout<<st<<" - "<<end<<" => "<<mid<<" - "<<tH<<endl;
        if(tH<=h)end=mid-1;  //  // try to minimize the speed(k) more...
        else st=mid+1;
    }
    return st;
}


int main(){
    vector<int>piles={332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    int hr=823855818;
    int k=minEatingSpeed(piles,hr);
    cout<<"Min. bananas-per-hour eating speed k is -> "<<k<<endl;
}