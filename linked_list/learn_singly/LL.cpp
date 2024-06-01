#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    int lengthofLL();
    void initList(vector<int>&);
    void printList();
    bool searchinLL(int);
    void deleteHead();
    void deleteTail();
    void deleteNode(int);
    void insertHead(int);
    void insertTail(int);
    void insertNode(int,int);
};

void LinkedList::insertHead(int val){
    Node* temp = new Node(val);
    temp->next = head;
    cout<<"Inserting at head: "<<val<<endl;
    head = temp;
}

void LinkedList::insertTail(int val){
    Node* temp = head;
    while (temp->next!=nullptr) temp = temp->next;
    cout<<"Inserting at tail: "<<val<<endl;
    temp->next = new Node(val);
}

void LinkedList::insertNode(int val, int k){
    if (head==nullptr) {
        if (k==1) head = new Node(val);
        cout<<"Inserting at position: "<<k<<" value: "<<val<<endl;
        return;
    }

    if (k==1){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        cout<<"Inserting at position: "<<k<<" value: "<<val<<endl;
        return;

    }

    int count = 0;
    Node* temp = head;
    while (temp!=nullptr){
        if (++count == k-1){
            Node* x = new Node(val);
            x->next = temp->next;
            cout<<"Inserting at position: "<<k<<" value: "<<val<<endl;
            temp->next = x;
            return;
        }

        temp = temp->next;
    }
}

void LinkedList::deleteNode(int k){
    if (head==nullptr) return;
    if (k==1) {
        Node* temp = head;
        head = head->next;
        cout<<"Delete at position: "<<k<<" value: "<<temp->data<<endl; 
        delete temp;
        return;
    } 

    int counter = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp!=nullptr){
        if (++counter == k){
            prev->next = prev->next->next;
            cout<<"Delete at position: "<<k<<" value: "<<temp->data<<endl; 
            delete temp;
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}

void LinkedList::deleteHead(){
    if (head==nullptr) return;
    Node* temp = head;
    cout<<"deleted head: "<<temp->data<<endl;
    head = head->next;
    delete temp;
}

void LinkedList::deleteTail(){
    if (head==nullptr || head->next==nullptr) return;
    Node* temp = head;

    while (temp->next->next!=nullptr) temp = temp->next;
    cout<<"Deleting tail: "<<temp->next->data<<endl;
    delete temp->next; 
    temp->next = nullptr;
}


int LinkedList::lengthofLL(){
    int count = 0;
    Node* temp = head;
    while (temp!=nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

bool LinkedList::searchinLL(int val){
    Node* temp = head;
    while (temp!=nullptr){
        if (temp->data==val) return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::initList(vector<int>& v){
    head = new Node(v[0]);
    Node* mover = head;
    for (int i=1;i<v.size();i++){
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover = mover->next; // i.e mover = temp;
    }
}

void LinkedList::printList(){
    Node* temp = head;
    while (temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    LinkedList* ll = new LinkedList();
    vector<int> arr = {24,35,67,12,34,98,103,23,43};
    ll->initList(arr);
    ll->printList();
    cout<<"length: "<<ll->lengthofLL()<<endl;
    cout<<"searching 12: "<<ll->searchinLL(12)<<endl;
    cout<<"searching 89: "<<ll->searchinLL(89)<<endl;
    ll->deleteHead();
    ll->printList();
    ll->deleteTail();
    ll->printList();
    ll->deleteNode(1);
    ll->printList();
    ll->deleteNode(3);
    ll->printList();
    ll->deleteNode(5);
    ll->printList();
    ll->deleteNode(78); // out of bounds value
    ll->printList();
    ll->insertHead(69);
    ll->printList();
    ll->insertTail(100);
    ll->printList();
    ll->insertNode(105, 4);
    ll->printList();
    ll->insertNode(99, 1);
    ll->printList();
    delete ll;
    return 0;
}