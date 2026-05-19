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

// 21. Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* curr=new ListNode(78998);
    ListNode* temp=curr;
    ListNode* temp1=list1;
    ListNode* temp2=list2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<temp2->val){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }else{
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
    while(temp1!=NULL){
        temp->next=temp1;
        temp1=temp1->next;
        temp=temp->next;
    }
    while(temp2!=NULL){
        temp->next=temp2;
        temp2=temp2->next;
        temp=temp->next;
    }
    return curr->next;
}

int main(){
    // list1
    ListNode* head=new ListNode(1);
    ListNode* a=new ListNode(9);
    ListNode* b=new ListNode(39);
    ListNode* c=new ListNode(49);
    ListNode* d=new ListNode(79);
    ListNode* e=new ListNode(191);
    head->next=a;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    display(head);
    cout<<endl;
    // list2
    ListNode* head1=new ListNode(16);
    ListNode* a1=new ListNode(59);
    ListNode* b1=new ListNode(89);
    ListNode* c1=new ListNode(109);
    ListNode* d1=new ListNode(199);
    ListNode* e1=new ListNode(1111);
    head1->next=a1;
    a1->next=b1;
    b1->next=c1;
    c1->next=d1;
    d1->next=e1;
    display(head1);
    cout<<endl;
    ListNode* head2=mergeTwoLists(head,head1);
    // list 3
    display(head2);
}