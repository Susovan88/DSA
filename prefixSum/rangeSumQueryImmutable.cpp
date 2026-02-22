#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 303. Range Sum Query - Immutable
class NumArray {
public:
    vector<int>prefixSum;
    int n;
    NumArray(vector<int>& arr) {
        n=arr.size();
        prefixSum.resize(n);
        // prefixsum...
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
    }
    int sumRange(int left, int right) {
        if(left>0) return prefixSum[right]-prefixSum[left-1];
        return prefixSum[right];
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    NumArray obj(arr);

    cout << obj.sumRange(0, 2) << endl; // 1+2+3 = 6
    cout << obj.sumRange(1, 3) << endl; // 2+3+4 = 9
    cout << obj.sumRange(2, 4) << endl; // 3+4+5 = 12

    return 0;
}