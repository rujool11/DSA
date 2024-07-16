// Leetcode 124. Binary Tree Maximum path sum

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
    int maxPathSum(TreeNode* root) {
        // at any node, max posible path sum = max sum on left + max sum on right
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }

    int helper(TreeNode* root, int& maxSum) {
        if (root == nullptr) return 0;

        int leftSum = max(0, helper(root->left, maxSum));
        int rightSum = max(0, helper(root->right, maxSum));
        // take max with 0, since if sum is negative, we choose not to include it in path

        maxSum = max(maxSum, leftSum + rightSum + root->val);
        // compare historical/ final max with the current max possible (l + r + current)

        return max(leftSum, rightSum) + root->val;
        // return max path (left or right), since either right one or left one has to be considered at every node
        // represents single path continuation, and path validity, so that only one child is
        // included at a time, and the path remains valid
        // like 1 + max(l, h) in depth

    }
};