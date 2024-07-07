#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node(int val) {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

int main() {

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(5);

    return 0;
}