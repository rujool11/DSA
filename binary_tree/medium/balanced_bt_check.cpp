// Leetcode 110. balanced binary tree

// basically modified depth function
// return -1 if unbalanced at any point
// if any one of left or right unbalanced, return -1
// else return the height/ depth of tree
// if result -1 is obtained, return false else return true

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


    int dfs_func(TreeNode* root) {
        
        if (root == nullptr) return 0;

        int left_height = dfs_func(root->left);
        int right_height = dfs_func(root->right);

        if (left_height == -1 || right_height == -1) return -1;

        if (abs(left_height - right_height) > 1) return -1;

        return max(left_height, right_height) + 1;

    }

    bool isBalanced(TreeNode* root) {
        return dfs_func(root) == -1 ? false : true;
    }
};