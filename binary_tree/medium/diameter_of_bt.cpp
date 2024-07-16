// Leetcode 543. Diameter of binary tree
// longest path between any two nodes, does not need to pass through root

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
    int diameterOfBinaryTree(TreeNode* root) {
        // at any node, longest path passing through that = left_height + right_height
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }

    int helper(TreeNode* root, int& diameter) {
        if (root == nullptr) return 0;

        int left_height = helper(root->left, diameter);
        int right_height = helper(root->right, diameter);
        diameter = max(diameter, left_height + right_height);

        return max(left_height, right_height) + 1;
    }
};