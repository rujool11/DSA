// GFG Boundary Traversal
// anticlockwise boundary traversal 

// Left boundary excluding leaf nodes
// Leaf nodes
// Right boundary in reverse excluding leaf nodes

// for leaf nodes, not good to do level order and all the leafs may not be on same level
// better to do inorder, traverse through all nodes and add leaf nodes to data structure when 
// we encounter them


class Solution {
public:
    bool isLeaf(Node* root) {
        if (root && !root->left && !root->right) return true;
        return false;
    }
    
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left; // since already added root before calling this
        
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addRightBoundaryInReverse(Node* root, vector<int>& res) {
        stack<int> temp; // since to add in reverse
        
        Node* curr = root->right;
        while (curr) {
            if (!isLeaf(curr)) temp.push(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        while (!temp.empty()) {
            res.push_back(temp.top());
            temp.pop();
        }
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        // using inorder, since in level order all leaves might not be on same level
        if (root == nullptr) return;
        
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        
        addLeaves(root->left, res);
        addLeaves(root->right, res);
        
    }
    
    vector <int> boundary(Node *root) {
        vector<int> res;
        if (root == nullptr) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundaryInReverse(root, res);
        return res;
    }
};

// --------------------------------------------------------------------------------------------------------
// Full code with driver code to see how to construct tree from level order, etc

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node* root) {
        if (root && !root->left && !root->right) return true;
        return false;
    }
    
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left; // since already added root before calling this
        
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addRightBoundaryInReverse(Node* root, vector<int>& res) {
        stack<int> temp; // since to add in reverse
        
        Node* curr = root->right;
        while (curr) {
            if (!isLeaf(curr)) temp.push(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        while (!temp.empty()) {
            res.push_back(temp.top());
            temp.pop();
        }
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        
        if (root == nullptr) return;
        
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        
        addLeaves(root->left, res);
        addLeaves(root->right, res);
        
    }
    
    vector <int> boundary(Node *root) {
        vector<int> res;
        if (root == nullptr) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundaryInReverse(root, res);
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends