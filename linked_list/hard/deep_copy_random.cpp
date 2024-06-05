// Leetcode 138. copy list with random pointer

// NAIVE SOLUTION --> 
/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Naive solutions: 
        // copy list without random nodes
        // while copying, keep a map {original_node, new_node}
        // iterate new linked list, adding random linkages, using this map

        if (head==nullptr) return head;

        map<Node*,Node*> m;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        Node* temp = head;
        while (temp!=nullptr){
            res->next = new Node(temp->val);
            res = res->next;
            m[temp] = res;
            temp = temp->next;
        }

        res = dummy->next;
        temp = head;
        while (res!=nullptr){
            res->random = m[temp->random];
            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};

//--------------------------------------------------------------------------------------------------------------
// Optimized solution -->

/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       // Optimized solution 
       // Instead of using map, append new node to the next of the linked list

        if (head==nullptr) return head;
        
        Node* temp = head;
        // insert new nodes between older ones
        while (temp!=nullptr){
            Node* nextEl = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextEl;
            temp->next = copy;
            temp = nextEl;
        }

        // connect the random pointers now
        temp = head;
        while (temp!=nullptr){
            if (temp->random) temp->next->random = temp->random->next;
            else temp->next->random = nullptr;
            temp = temp->next->next;
        }   

        // disconnect added nodes
        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while (temp!=nullptr){
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next; // remove added nodes
            temp = temp->next;
        }
        
        return dummy->next;
    }
};