#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node* prev;

    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    };
};

class  DoublyLinkedList{   // user define data structure
    public:
    Node *head;
    Node *tail;
    int size;

    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    };

    void insertAtTail(int val){
        Node *temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }

    void insertAtHead(int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }

    void insertAt(int idx,int val){
        if(idx<0 || idx>size){
            cout<<"invalid Index!"<<endl;
        }
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtTail(val);
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
            newNode->prev=temp;
            newNode->next->prev=newNode;
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
            head->prev=NULL;
            size--;
        }
    }

    void deleteAtTail(){
        if(size==0)cout<<"Linklist is empty!";
        else if(size==1){
            head=tail=NULL;
            size--;
        }else{
            tail=tail->prev;
            tail->next=NULL;
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
            temp->next->prev=temp;
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

    void reverseDispay(){
        Node *temp=tail;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

};

int main(){
    DoublyLinkedList l;
    l.insertAt(0,76);
    l.insertAtTail(8);
    l.display();
    l.insertAt(0,12);
    l.insertAtTail(87);
    l.display();
    l.insertAt(2,71);
    l.display();
    l.deleteAt(2);
    l.display();
    l.reverseDispay();
}
