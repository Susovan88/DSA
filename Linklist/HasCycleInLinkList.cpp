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

// 141. Linked List Cycle
bool hasCycle(ListNode *head) {
    if(head==NULL) return false;
    ListNode* slow=head->next;
    ListNode* fast=head->next==NULL?NULL : head->next->next;
    if(slow==NULL && fast==NULL) return false;
    while(slow!=fast){
        if(slow==NULL || fast==NULL || fast->next==NULL) return false;
        slow=slow->next;
        fast=fast->next->next;
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
    e->next=b;
    cout<<hasCycle(head);
}