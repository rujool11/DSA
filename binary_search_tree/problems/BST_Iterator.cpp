// Leetcode 173. BST Iterator

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> st;
public:
    // basic solution -> store inorder and do , constant time, O(n) space
    // Space optimized -> O(H)
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        pushAll(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* curr) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */