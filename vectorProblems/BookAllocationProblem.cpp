#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int stu = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) return false;

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            stu++;
            pages = arr[i];
        }
    }
    return stu <= m;
}

int allocateBooks(vector<int>& arr, int n, int m) {
    int ans = -1;
    if (m > n) return -1;

    int sum = 0, maxElement = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxElement = max(maxElement, arr[i]);
    }

    int st = maxElement, end = sum, mid;
    while (st <= end) {
        mid = st + (end - st) / 2; // Max allowed pages

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1; // Try to minimize the maximum pages assigned
        } else {
            st = mid + 1; // Increase the limit if it's not valid
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;
    cout << allocateBooks(arr, n, m);
}
 