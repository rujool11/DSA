// Leetcode 99. Recover Binary Search Tree

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
    void getInorder(TreeNode* root, TreeNode*& first, TreeNode*& middle, TreeNode*& last, TreeNode*& prev) {
        if (!root) return;

        getInorder(root->left, first, middle, last, prev);
        if (prev && root->val < prev->val) {
            if (first && middle) {
                last = root;
            }
            else {
                first = prev;
                middle = root;
            }
        }
        prev = root;
        getInorder(root->right, first, middle, last, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *middle = nullptr, *last = nullptr;
        TreeNode* prev = nullptr;
        getInorder(root, first, middle, last, prev);
        if (first && last) swap(first->val, last->val);
        else swap(first->val, middle->val); 
    }
};