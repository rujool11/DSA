// Leetcode 145. Binary Tree Postorder Traversal
// 2 stack iterative approach


// use 2 stacks
// push root to stack1
// while loop till stack1 is not empty ->
// set root to top, and pop from stack1
// push this root to stack2, and also push left and right children , if they exist, to stack1 (in that order)
// while loop till stack2 is not empty ->
// add value of top to result, and pop


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

    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> res;
       if (root == nullptr) return res;

       stack<TreeNode*> st1;
       stack<TreeNode*> st2;

       st1.push(root);
       while (!st1.empty()) {
           root = st1.top();
           st1.pop();

           st2.push(root);
           if (root->left) st1.push(root->left);
           if (root->right) st1.push(root->right);
           
       }

       while (!st2.empty()) {
           res.push_back(st2.top()->val);
           st2.pop();
       }

       return res;
    }
};