#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Node{ // user define data type
    public:
    int val;
    Node *next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    };
};

class  LinkList{   // user define data structure
    public:
    Node *head;
    Node *tail;
    int size;

    LinkList(){
        head=NULL;
        tail=NULL;
        size=0;
    };

    void insertAtEnd(int val){
        Node *temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }

    void insertAtBegin(int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            temp->next=head;
            head=temp;
        }
        size++;
    }

    void insertAt(int idx,int val){
        if(idx<0 || idx>size){
            cout<<"invalid Index!"<<endl;
        }
        else if(idx==0) insertAtBegin(val);
        else if(idx==size) insertAtEnd(val);
        else{
            Node *temp=head;
            Node *newNode=new Node(val);
            int j=0;
            while(j!=idx-1){
                temp=temp->next;
                j++;
            }
            newNode->next=temp->next;
            temp->next=newNode;
            size++;
        }
    }

    void deleteAtHead(){
        if(size==0)cout<<"Linklist is empty!";
        else if(size==1){
            head=tail=NULL;
            size--;
        }
        else{
            head=head->next;
            size--;
        }
    }

    void deleteAtTail(){
        if(size==0)cout<<"Linklist is empty!";
        else if(size==1){
            head=tail=NULL;
            size--;
        }else{
            Node *temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
        }
    }

    void deleteAt(int idx){
        if(idx<0 || idx>=size){
            cout<<"invalid Index!"<<endl;
        }
        if(size==0)cout<<"Linklist is empty!";
        else if (idx==0) deleteAtHead();
        else if (idx==size-1) deleteAtTail();
        else{
            Node *temp=head;
            int i=0;
            while(i<idx-1){
                temp=temp->next;
                i++;
            }
            temp->next=temp->next->next;
            size--;
        }
    }

    int get(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid Index : "<<idx<<endl;
            return -1;
        }
        else if(idx==0) return head->val;
        else if (idx==size-1) return tail->val;
        else{
            int i=0;
            Node *temp=head;
            while(i!=idx){
                temp=temp->next;
                i++;
            }
            return temp->val;
        }
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    LinkList l;
    l.insertAtEnd(89);
    l.display();
    l.insertAtEnd(80);
    l.insertAtEnd(12);
    l.display();
    cout<<l.size<<endl;

    l.insertAtBegin(12);
    l.insertAtEnd(34);
    l.insertAtBegin(65);
    l.insertAtBegin(16);
    l.insertAtEnd(3);
    l.insertAt(2,32);
    l.display();
    cout<<l.size<<endl;

    l.insertAt(3,11);
    l.insertAt(1,23);
    l.display();
    cout<<l.size<<endl;
    l.deleteAtHead();
    l.display();
    l.deleteAtTail();
    l.display();
    cout<<l.size<<endl;

    l.deleteAt(3);
    l.display();
    l.deleteAt(1);
    l.display();
    cout<<l.size<<endl;

    // cout<<l.get(2)<<" "<<l.get(4)<<" "<<l.get(-9)<<endl;
}