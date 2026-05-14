#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
For Count Number of Nice Subarrays, use a sliding window with two pointers. Maintain the count of odd numbers inside the window. 
When the window contains exactly k odds, count how many valid starting positions are possible by moving the left pointer over leading even numbers. 
Each movement gives another valid subarray because removing even numbers does not change the odd count. Store this count in c and add it to the answer for every j. 
If odds become greater than k, shrink the window and reset c because previous starting positions are no longer valid.
*/

// 1248. Count Number of Nice Subarrays
int numberOfSubarrays(vector<int>& nums, int k) {
    int n=nums.size();
    int i=0,j=0;
    int ans=0;
    int c=0;
    int odds=0;
    while(j<n){
        odds+=(nums[j]%2);
        if(odds==k)c=0;
        while(odds==k){
            odds-=(nums[i]%2);
            c++;
            i++;
        }
        ans+=c;
        j++;
    }
    return ans;
}

int main(){
    vector<int>arr={2,2,2,2,1,1,2,1,2,2,2,1,2,1,2,2,1,2};
    int k=3;
    cout<<numberOfSubarrays(arr,k);
}