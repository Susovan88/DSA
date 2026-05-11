#include <bits/stdc++.h>
using namespace std;

// 1109. Corporate Flight Bookings
vector<int> corpFlightBookings(vector<vector<int>>& nums, int n) {
    vector<int>ans(n,0);

    for(auto ele : nums){
        ans[ele[0]-1]+=ele[2];
        if(ele[1]<n)ans[ele[1]]+=-ele[2];
    }
    // prefix sum
    for(int i=1;i<n;i++){
        ans[i]+=ans[i-1];
    }
    return ans;
}

int main() {

    vector<vector<int>> nums = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };

    int n = 5;

    vector<int> ans = corpFlightBookings(nums, n);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}