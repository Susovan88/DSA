#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void displayQueue(queue<int> &qu){
     cout<<" =>> ";
    for(int i=0;i<qu.size();i++){
        int a=qu.front();
        qu.pop();
        cout<<a<<" ";
        qu.push(a);
    }
    cout<<endl;
}

void removeLastKthElements(queue<int>&qu,int k){
    int n=qu.size();
    for(int i=0;i<n-k;i++){
        qu.push(qu.front());
        qu.pop();
    }
    for(int i=0;i<k;i++){
        qu.pop();
    }
    cout<<"Last "<<k<<" elements are removed successfully !!! ";
    displayQueue(qu);
}

int main(){
    queue<int> qu;
    int k=4;
    
    qu.push(91);
    qu.push(93);        
    qu.push(95);
    qu.push(7);
    qu.push(1);
    qu.push(3);
    qu.push(5);
    qu.push(17);
    qu.push(81);
    displayQueue(qu);
    removeLastKthElements(qu,k);
    
}