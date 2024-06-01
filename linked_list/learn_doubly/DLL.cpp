#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }

    Node(int data, Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void initList(vector<int>&);
    void printList();
    void deleteHead();
    void deleteTail();
    void deleteNode(int);
    void insertHead(int);
    void insertTail(int);
    void insertNode(int,int);
    void reverse();
};

void LinkedList::insertHead(int val){
    Node* temp = new Node(val, head, nullptr);
    head->back = temp;
    cout<<"Inserting head: "<<val<<endl;
    head = temp;
    return;
}

void LinkedList::insertNode(int val, int k){
    Node* temp = head;
    // can add conditions for k = 1, if head is nullptr, etc like in singly linked list
    cout<<"Inserting node "<<val<<" at position "<<k<<endl;

    int count = 0;
    while (temp!=nullptr){
        if (++count == k-1){
            Node* nn = new Node(val, temp->next, temp);
            temp->next->next->back = nn;
            temp->next = nn;
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::insertTail(int val){
    Node* temp = head;
    cout<<"Inserting tail: "<<val<<endl;
    while (temp->next!=nullptr) temp = temp->next;
    temp->next = new Node(val, nullptr, temp);
}

void LinkedList::deleteHead(){
    if (head==nullptr || head->next==nullptr) return;

    cout<<"Deleting head: "<<head->data<<endl;
    Node* prev = head;
    head = head->next;
    prev->next = nullptr;
    head->back = nullptr;
    delete prev;
}


void LinkedList::deleteNode(int k){
    if (head==nullptr) return;

    int count = 0;
    Node* temp = head;

    while (temp!= nullptr){
        if (++count ==k){
            cout<<"Delete at position "<<k<<" value: "<<temp->data<<endl;
            temp->back->next = temp->next;
            temp->next->back = temp->back;
            temp->back = nullptr;
            temp->next = nullptr;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::deleteTail(){
    if (head==nullptr || head->next==nullptr) return;

    Node* temp = head;

    while (temp->next!=nullptr) temp = temp->next;
    cout<<"Deleting tail: "<<temp->data<<endl;
    temp->back->next = nullptr;
    temp->back = nullptr;
    delete temp;
}

void LinkedList::initList(vector<int>& v){
    head = new Node(v[0]);
    Node* prev = head;
    for (int i=1;i<v.size();i++){
        Node* temp = new Node(v[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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
    vector<int> arr = {26,43,23,87,97,2,67,82,10};
    ll->initList(arr);
    ll->printList();
    ll->deleteHead();
    ll->printList();
    ll->deleteTail();
    ll->printList();
    ll->deleteNode(3);
    ll->printList();
    ll->insertHead(100);
    ll->printList();
    ll->insertTail(150);
    ll->printList();
    ll->insertNode(200, 4);
    ll->printList();
    ll->deleteNode(4);
    ll->printList();
    ll->insertNode(34,2);
    ll->printList();
    ll->insertNode(33,2);
    ll->printList();
    ll->deleteNode(4);
    ll->printList();
    return 0;
}