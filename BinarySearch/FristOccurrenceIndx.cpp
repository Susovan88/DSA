#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,2,2,2,2,3,3,3,3,5,5,5,6,6,6,8,8,8,8,9,9,9};
    int t = 2;
    int st = 0, end = arr.size() - 1;
    int firstIndex = -1; // Store the first occurrence index

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == t) {
            firstIndex = mid;  // Store potential first occurrence
            end = mid - 1;      // Keep searching in the left half
        } else if (arr[mid] < t) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (firstIndex != -1)
        cout << "Index: " << firstIndex << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
