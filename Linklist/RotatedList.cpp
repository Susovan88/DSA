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

// 61. Rotate List
ListNode* rotateRight(ListNode* head, int k) {
    ListNode* curr=new ListNode(8);
    curr->next=head;
    ListNode* temp=head;
    int n=0; // size 
    while(temp!=NULL){
        temp=temp->next;
        n++;
    }
    if(n==0 || n==1 || k==0) return head;
    temp=head;
    k=k%n;
    if(k==0) return head;
    int kth=n-k;
    for(int i=1;i<kth;i++){
        temp=temp->next;
    }
    curr->next=temp->next;
    temp->next=NULL;
    temp=curr->next;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    return curr->next;
}

int main(){
    ListNode* head=new ListNode(19);
    ListNode* a=new ListNode(9);
    ListNode* b=new ListNode(319);
    ListNode* c=new ListNode(109);
    ListNode* d=new ListNode(199);
    ListNode* e=new ListNode(191);
    head->next=a;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    display(head);
    cout<<endl;
    head=rotateRight(head,3);
    display(head);
}