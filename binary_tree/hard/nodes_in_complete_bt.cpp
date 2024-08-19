// Leetcode 222. Count Complete Tree Nodes

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
// complete bt -> nodes at last level as far left as possible
class Solution {
public:
    int countNodes(TreeNode* root) {
        // if all nodes -> 2^height - 1
        // complete tree may have some nodes missing at right at last level (full from left)
        // T(n) = O(log^2(n))

        if (root == nullptr) return 0;
        int leftHeight = countLeftHeight(root);
        int rightHeight = countRightHeight(root);

        if (leftHeight == rightHeight) return (1 << leftHeight) - 1; // 2^h - 1

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // this height calculation is possible since complete binary tree
    int countLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }

    int countRightHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->right;
            height++;
        }
        return height;
    }


};