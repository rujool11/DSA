// Leetcode 94. Binary Tree Inorder Traversa/


// Use stack
// set node to root, run infinite while loop that will terminate when stack is empty
// this is done because root is not pushed onto the stack at the start
// while node exists, keep going as left as you can (node->left), while pushing node to stack
// if node is null-> 
// if stack empty then break
// set node to top of stack, and pop the top
// add value to result, and go right (node->right)

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

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if (root == nullptr) return res;
        TreeNode* node = root;

        stack<TreeNode*> st;
        while (true) {
            if (node) {
                st.push(node);
                node = node->left;
            }

            else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }

        return res;
    }
};