#include <iostream>
#include <vector>
using namespace std;

class Queue{
    public:
    int f;
    int b;
    vector<int>arr;

    Queue(int n){
       f=0;
       b=0;
       vector<int>v(n);
       arr=v;
    }
    void push(int a){
        if(b==arr.size()){
            cout<<" -> Overflow !!!"<<endl;
            return;
        }
        arr[b]=a;
        b++;
    }
    void pop(){
        if(b-f==0){
            cout<<" -> Underflow !!!"<<endl;
            return;
        }
        f++;
    }
    int front(){
        if(b-f==0){
            cout<<" -> Underflow !!!"<<endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(b-f==0){
            cout<<" -> Underflow !!!"<<endl;
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        return (f-b)==0? true:false;
    }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Queue qu(6);
    qu.pop();
    qu.push(91);
    qu.push(93);
    qu.push(95);
    qu.push(7);
    qu.push(1);
    qu.push(3);
    qu.push(5);
    qu.push(17);
    qu.push(81);
    qu.display();

    cout<<qu.front()<<" ";
    cout<<qu.back()<<" ";
    cout<<qu.size()<<" ";
    qu.pop();
    qu.pop();
    cout<<qu.front()<<" ";
    cout<<qu.back()<<" ";
    cout<<qu.size()<<endl;

    qu.display();

}