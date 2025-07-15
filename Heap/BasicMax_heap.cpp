#include <iostream>
#include <queue> 
#include <string>
#include <vector>
using namespace std;


int main(){
    priority_queue<int>pq;  // default max heap
    pq.push(89);
    pq.push(9);
    pq.push(8);
    pq.push(19);
    pq.push(81);
    pq.push(29);
    pq.push(49);

    while(pq.size()!=0){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}