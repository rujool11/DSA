// Leetcode 98. Validate BST

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

    // do recursive solution once (not passing because of dumb null nodes in test case)
public:

    bool isValidBST(TreeNode* root, long min, long max) {
        if (!root) return true;

        if (root->val >= max || root->val <= min) return false;
        return isValidBST(root->left, min, root->val)
                && isValidBST(root->right, root->val, max);
    }
     
    bool isValidBST(TreeNode* root) {
        // one solution -> inorder, and check if it is in ascending
        // no extra space solution ->

        return isValidBST(root, LONG_MIN, LONG_MAX);

    }
};