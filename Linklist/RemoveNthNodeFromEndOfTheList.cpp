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

// 19. Remove Nth Node From End of List
ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode* slow=head;
    ListNode* fast=head;
    for(int i=1;i<=n;i++){
        fast=fast->next;
    }
    if(fast==NULL) return head->next;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return head;
}
ListNode* removeNthFromEnd2(ListNode* head, int n) {
    int count=0;
    ListNode* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(count==1 && n==1) return NULL;
    temp=head;
    int nth=count-n;
    count=1;
    if(nth==0) return head->next;
    while(count<nth){
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;
    return head;
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
    head=removeNthFromEnd1(head,3);
    display(head);
}