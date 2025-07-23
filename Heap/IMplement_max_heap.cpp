#include <iostream>
#include <queue> 
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


class MaxHeap {
public:
    vector<int> arr;
    int currSize;
    int fixedSize;

    MaxHeap(int x) {
        arr.resize(x + 1);  // 1-based indexing
        currSize = 0;
        fixedSize = x;
    }

    void push(int val) {
        if (currSize < fixedSize) {
            currSize++;
            arr[currSize] = val;
            int idx = currSize;

            while (idx > 1) {
                int parentIdx = idx / 2;
                if (arr[parentIdx] < arr[idx]) {
                    swap(arr[parentIdx], arr[idx]);
                    idx = parentIdx;
                } else break;
            }
        } else {
            cout << "Push() -> Not possible. Heap is full!" << endl;
        }
    }

    void pop() {
        if (currSize == 0) {
            cout << "Pop() -> Not possible. Heap is empty!" << endl;
            return;
        }

        arr[1] = arr[currSize];
        currSize--;
        int idx = 1;

        while (true) {
            int left = idx * 2;
            int right = idx * 2 + 1;
            int largest = idx;

            if (left <= currSize && arr[left] > arr[largest]) largest = left;
            if (right <= currSize && arr[right] > arr[largest]) largest = right;

            if (largest != idx) {
                swap(arr[idx], arr[largest]);
                idx = largest;
            } else break;
        }
    }

    int top() {
        if (currSize > 0) return arr[1];
        cout << "Top() -> Not possible. Heap is empty!" << endl;
        return -1;
    }

    int size() {
        return currSize;
    }
    void display(){
        for(int j=1;j<=currSize;j++)cout<< arr[j]<<" ";
        cout<<endl;
    }
};



int main(){
    MaxHeap mxH(6);
    cout<<mxH.top()<<endl;
    mxH.pop();
    mxH.push(89);
    mxH.push(9);
    mxH.push(18);
    cout<<mxH.top()<<" "<<mxH.size()<<endl;
    mxH.pop();
    cout<<mxH.top()<<" "<<mxH.size()<<endl;
    mxH.push(10);
    mxH.push(87);
    mxH.push(23);
    mxH.display();
    cout << mxH.top() << " " << mxH.size() << endl;
    mxH.pop();
    mxH.pop();
    mxH.display();
    cout<<mxH.top()<<" "<<mxH.size()<<endl;
    mxH.push(27);
    mxH.push(53);
    mxH.push(17);
    mxH.push(63);
    cout<<mxH.top()<<" "<<mxH.size()<<endl;
}