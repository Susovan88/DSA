#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/?update=google&purpose=signup&source=problem-page

int main(){
    int n;
    cin>>n;
    vector<int>box(n+1,0);   // 1 -> n
    int m;
    cin>>m;

    // option 1 -> using dp 
    vector<int>left(n+1,0),right(n+1,0);  // left count , right count
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        left[l]++;
        right[r]++;
    }
    box[1]=left[1]; // base case
    for(int i=2;i<=n;i++){
        box[i]=left[i]-right[i-1]+box[i-1];
    }

    // // option 1 -> using prefix sum 
    // for(int i=0;i<m;i++){
    //     int l,r;
	// 	cin>>l>>r;
	// 	box[l]++;
	// 	if(r!=n) box[r+1]--;
    // }
	// for(int i=2;i<=n;i++){
	// 	box[i]+=box[i-1];
	// }

    vector<int>count(10000007,0);
    for(int i=1;i<=n;i++){ // store all counts of coins 
        count[box[i]]++;
    }

    // sufix sum
    for(int i=count.size()-2;i>=0;i--){
        count[i]+=count[i+1];
    }

    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        int num;
        cin>>num;
        cout<<count[num]<<endl;
    }
}