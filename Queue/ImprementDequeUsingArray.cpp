#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
public:
    int f,b;
    int i,size;
    vector<int>arr;
    MyCircularDeque(int k) {
        vector<int>a(k);
        arr=a;
        size=k;
        i=0;
        f=-1,b=-1;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(f==-1&&b==-1){
            f++;b++;
            arr[f]=value;
            i++;
            return true;
        }
        f--;
        f=(f+size)%size;
        arr[f]=value;
        i++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(f==-1&&b==-1){
            f++;b++;
            arr[b]=value;
            i++;
            return true;
        }
        b++;
        b=b%size;
        arr[b]=value;
        i++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(f==0 && b==0){
            f=-1;
            b=-1;
            i=0;
            return true;
        }
        f++;
        f=f%size;
        i--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(f==0 && b==0){
            f=-1;
            b=-1;
            i=0;
            return true;
        }
        b--;
        i--;
        b=(b+size)%size;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[f];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[b];
    }
    
    bool isEmpty() {
        return i==0? true:false;
    }
    
    bool isFull() {
        return i==size? true:false;
    }
};


int main(){
    MyCircularDeque qu(5);
    cout << qu.insertLast(1) << endl;  // returns true
    cout << qu.insertLast(2) << endl;  // returns true
    cout << qu.insertFront(3) << endl; // returns true
    cout << qu.getRear() << endl;      // returns 2
    cout << qu.isFull() << endl;       // returns false
    cout << qu.deleteLast() << endl;   // returns true
    cout << qu.insertFront(4) << endl; // returns true
    cout << qu.getFront() << endl;     // returns 4
    return 0;
}