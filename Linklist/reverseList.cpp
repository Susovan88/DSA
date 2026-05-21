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

// 206. Reverse Linked List
ListNode* reverseList(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* nxt=NULL;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

ListNode* rev(ListNode* head,ListNode* &newHead) {
    if(head->next==NULL){
        newHead=head;
        return head;
    }
    ListNode* rem=rev(head->next,newHead);
    rem->next=head;
    head->next=NULL;
    rem=rem->next;
    return rem;
}
ListNode* reverseList1(ListNode* head){
    if(head==NULL) return NULL;
    ListNode* newHead=NULL;
    rev(head,newHead);
    return newHead;
}

// 92. Reverse Linked List II
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* newHead=new ListNode(-900);
    newHead->next=head;
    ListNode* temp=newHead;
    ListNode* last=newHead;
    int i=0;
    while(temp!=NULL && i!=left){
        last=temp;
        temp=temp->next;
        i++;
    }
    ListNode* curr=temp;
    ListNode* prev=NULL;
    ListNode* nxt=NULL;

    // revrese
    while(curr!=NULL && i<=right){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        i++;
    }
    temp->next=curr;
    last->next=prev;
    return newHead->next;
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
    head=reverseList1(head);
    display(head);
    cout<<endl;
    head=reverseBetween(head,2,4);
    display(head);
}