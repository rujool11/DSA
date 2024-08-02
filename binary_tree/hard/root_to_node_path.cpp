// GFG root to node path in binary tree


// start from root, add each node to array when we reach that node
// if no match found, call left and then call right
// when we reach null, return false
// so, leaf nodes will get false from both left and right
// then, pop current value, and go to parent node

class Solution {
  public:
    bool getPath(Node* root, vector<int>& arr, int x) {
        
        if (root == nullptr) return false;
        arr.push_back(root->data);
        
        if (root->data == x) return true;
        
        if (getPath(root->left, arr, x) ||
            getPath(root->right, arr, x)) return true;
        
        arr.pop_back(); // if not found at left or right, then pop
        return false;
        
    }
    
    bool isLeaf(Node* x) {
        return (x && !x->left && !x->right);
    }
    
    void getLeavesRec(Node* root, vector<int>& leaves) {
        if (root == nullptr) return;
        
        if (isLeaf(root)) {
            leaves.push_back(root->data);
            return;
        }
        
        getLeavesRec(root->left, leaves);
        getLeavesRec(root->right, leaves);
    }
    
    vector<int> getLeaves(Node* root) {
        vector<int> leaves;
        getLeavesRec(root, leaves);
        return leaves;
    }
    
    vector<vector<int>> Paths(Node* root) {
        
        vector<vector<int>> ans;
        vector<int> leaves = getLeaves(root);
        
        for (auto x: leaves) {
            vector<int> arr;
            getPath(root, arr, x);
            ans.push_back(arr);
        }
        
        return ans;
        
    }
};