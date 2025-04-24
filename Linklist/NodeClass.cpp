#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    };
};

int main(){

    Node a(8);
    Node b(99);
    Node c(78);
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    // cout<<a.val<<" "<<b.next<<endl;
    // a.next->val=909;
    // cout<<b.val<<" "<<a.next->val;

    Node * temp=&a;
    while(temp!=NULL){
        cout<<temp->val<<' ';
        temp=temp->next;
    }

}