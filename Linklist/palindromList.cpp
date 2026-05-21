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
// 234. Palindrome Linked List
bool isPalindrome(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* rev=reverseList(slow->next);
    slow=head;
    fast=rev;
    while(slow!=NULL && fast!=NULL){
        if(slow->val!=fast->val) return false;
        slow=slow->next;
        fast=fast->next;
    }
    return true;
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
    cout<<isPalindrome(head);
}