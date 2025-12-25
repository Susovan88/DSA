#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include <vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*>mp;  // <curr_node , copy_node>

    Node* dummy=new Node(0);
    Node* temp=head;
    Node* tempC=dummy;

    while(temp){
        tempC->next=new Node(temp->val);
        tempC=tempC->next;
        mp[temp]=tempC;
        temp=temp->next;
    }

    for(auto el : mp){
        temp=el.first;
        tempC=el.second;
        tempC->random=temp->random? mp[temp->random]: NULL;
    }

    return dummy->next;

}

int main() {
    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    // Set next pointers
    n1->next = n2;
    n2->next = n3;

    // Set random pointers
    n1->random = n3;   // 1 -> 3
    n2->random = n1;   // 2 -> 1
    n3->random = n2;   // 3 -> 2

    // Copy list
    Node* copiedHead = copyRandomList(n1);

    // Print original list
    cout << "Original List:\n";
    Node* temp = n1;
    while (temp) {
        cout << "Val: " << temp->val << ", Random: ";
        cout << (temp->random ? temp->random->val : -1) << endl;
        temp = temp->next;
    }

    // Print copied list
    cout << "\nCopied List:\n";
    temp = copiedHead;
    while (temp) {
        cout << "Val: " << temp->val << ", Random: ";
        cout << (temp->random ? temp->random->val : -1) << endl;
        temp = temp->next;
    }

    return 0;
}
