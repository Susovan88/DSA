#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int x) {
    int n = arr.size();
    int st = 0, end = n - 1;
    int mid;
    while (st <= end) {
        mid = st + (end - st) / 2; 
        if (arr[mid] == x) 
            return mid;
        else if (arr[mid] < x) 
            st = mid + 1;
        else 
            end = mid - 1;
    }
    return -1; 
}

//using recursion
int recBinarySearch(vector<int>&arr,int x,int st,int end){
    int mid;
    if(st<end){
        mid=st+(end-st)/2;
        if(arr[mid]<x) return recBinarySearch(arr,x,mid+1,end);
        else if(arr[mid]>x) return recBinarySearch(arr,x,st,mid-1);
        else return mid;
    }
}

int main() {
    vector<int> arr = {9,10, 12,30, 34,50, 67,87, 90, 99};
    int x = 87;
    // int index = binarySearch(arr, x);
    int index = recBinarySearch(arr,x,0,arr.size()-1);
    cout << index;
    return 0;
}
