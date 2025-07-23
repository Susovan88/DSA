#include <iostream>
#include <queue> 
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


class MinHeap{
    public:
    vector<int>arr;
    int i;
    int currSize;
    int fixedSize;

    MinHeap(int x){
        vector<int>a(x+1);
        this->arr=a;
        this->i=1;
        this->currSize=0;
        this->fixedSize=x;
    }

    void push(int val){
        if(i<=fixedSize){
            arr[i]=val;
            int idx=i;
            while(idx!=1){
                int parentIdx=idx/2;
                if(arr[parentIdx]>arr[idx]){
                    swap(arr[parentIdx],arr[idx]);
                    idx=parentIdx;
                }else break;
            }
            i++;
            currSize++;
        }else cout<<"Push() -> Not prossible. length is fixed!!!"<<endl;
    }

    void pop(){
        if(i!=1){
            this->arr[1]=this->arr[i-1];  
            i--;currSize--;
            int idx=1;         
            while(true){
                int left=idx*2,right=idx*2+1;
                if(left>=i)break;
                if(right>=i){
                    if(arr[left]<arr[idx]){
                        swap(arr[left],arr[idx]);
                        idx=left;
                    }
                    else break;
                }
                else if(arr[left]<arr[right]){
                    if(arr[left]<arr[idx]){
                        swap(arr[left],arr[idx]);
                        idx=left;
                    }else break;
                }
                else{
                    if(arr[right]<arr[idx]){
                        swap(arr[right],arr[idx]);
                        idx=right;
                    }else break;
                }
            }
        }else cout<<"Pop() -> Not Prossible -> length is Zero!"<<endl;
    }
    int top(){
        if(i!=1){
            return arr[1];
        }else cout<<"Top() -> Not Prossible -> length is Zero!"<<endl;
        return -1;
    }
    int size(){
        return currSize;
    }

};


int main(){
    MinHeap mnH(6);
    cout<<mnH.top()<<endl;
    mnH.pop();
    mnH.push(89);
    mnH.push(9);
    mnH.push(18);
    cout<<mnH.top()<<" "<<mnH.size()<<endl;
    mnH.pop();
    cout<<mnH.top()<<" "<<mnH.size()<<endl;
    mnH.push(10);
    mnH.push(87);
    mnH.push(23);
    cout<<mnH.top()<<" "<<mnH.size()<<endl;
    mnH.pop();
    mnH.pop();
    cout<<mnH.top()<<" "<<mnH.size()<<endl;
    mnH.push(27);
    mnH.push(53);
    mnH.push(17);
    mnH.push(63);
    cout<<mnH.top()<<" "<<mnH.size()<<endl;
}