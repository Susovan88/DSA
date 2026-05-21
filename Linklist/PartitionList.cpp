#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode *next=NULL;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

void display(ListNode* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    display(head->next);
}

// 86. Partition List
ListNode* partition(ListNode* head, int x) {
    ListNode* newHead=new ListNode(-1);
    ListNode* left=new ListNode(-1);
    ListNode* right=new ListNode(-1);
    ListNode* temp=head;
    ListNode* tl=left; // temp left
    ListNode* tr=right; // temp right
    while(temp!=NULL){
        if(temp->val<x){
            tl->next=temp;
            tl=tl->next;
        }else{
            tr->next=temp;
            tr=tr->next;
        }
        temp=temp->next;
    }
    if(left->next!=NULL && right->next!=NULL){
        newHead->next=left->next;
        tl->next=right->next;
        tr->next=NULL;
        return newHead->next;
    }
    else if(left->next==NULL) return right->next;
    return left->next;
}

int main(){
    ListNode* head=new ListNode(109);
    ListNode* a=new ListNode(9);
    ListNode* b=new ListNode(19);
    ListNode* c=new ListNode(179);
    ListNode* d=new ListNode(39);
    ListNode* e=new ListNode(11);
    head->next=a;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    display(head);
    cout<<endl;
    head=partition(head,100);
    display(head);
}