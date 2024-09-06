// 235. LCA in BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // O(n) = T(H) H being height of tree
        if (!root) return nullptr;
        int curr = root->val;

        if (curr < p->val && curr < q->val) return lowestCommonAncestor(root->right, p, q);
        if (curr > p->val && curr > q->val) return lowestCommonAncestor(root->left, p, q);
        return root; // if both nodes on either side, then that root will be LCA

    }
};