// Leetcode 101. Symmetric Tree

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left || !right) return (left == right);

       return (left->val == right->val &&
       isMirror(left->left, right->right) &&
       isMirror(left->right, right->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};