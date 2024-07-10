// Leetcode 144. Binary Tree Preorder Traversal
// Iterative traversal

// Stack is used
// push root to stack, iterate till stack is not empty
// set root to top of stack, and pop the top
// add value of top to result, and push right and left children of root to stack 
// (in order R - L since we want Root - L - R and stack is LIFO)

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
class Solution {
public:
    // push root in stack, and print/ add to ans. 
    // then, first push right, then left (since root -> L -> R, thus to traverse L first, stack if LIFO)
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;

        stack<TreeNode*> st;
        st.push(root);

        if (root == nullptr) return res;

        while (!st.empty()) {

            root = st.top();
            st.pop();
            res.push_back(root->val);

            if (root->right) st.push(root->right);
            if (root->left) st.push(root->left);

        }

        return res;
    }
};