#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int minProductOfSubset(vector<int>arr){
    int cz=0,cp=0,cn=0; // counts of -ve ,0, +ve
    int pn=1,pp=1;  // products of all -ve and +ve;
    int mxE=INT_MIN; // max -ve 
    for(int ele:arr){
        if(ele<0){ //-ve
            cn++;
            pn*=ele;
            mxE=max(mxE,ele);
        }
        else if(ele==0) cz++;  //0
        else{ // +ve
            cp++;
            pp*=ele;
        }
    }
    if(cn==0){ // +ve
        if(cz!=0) return 0;
        else return *min_element(arr.begin(),arr.end());  //  return address of min element. 
    }else{ // -ve
        if( cn%2==0) return (pn/mxE)*pp;
        else return pn*pp; 
    }
}

int main(){
    vector<int>arr{-2,-3,1,4,-2,-4,1,0,9,-6,-1,-2,-1,-8,0};
    cout<<minProductOfSubset(arr);
}