#include <iostream>
using namespace std;

int main() {
    int arr[] = {7, 1, 5, 2, 8, 4, 9, 3, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    int maxS = sum;
    for (int i = k; i < n; i++) {
        sum = sum - arr[i - k] + arr[i];
        if (maxS < sum) 
            maxS = sum;
    }
    cout << "max Kth sum is - " << maxS << endl;
    return 0;
}
