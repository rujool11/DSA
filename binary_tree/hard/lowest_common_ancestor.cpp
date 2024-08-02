// Leetcode 236. Lowest Common Ancestor of a Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // naive -> find both paths and ..

        // This solution ->
        // use recursive/ DFS traversal (go left and then go right)
        // if either p or q found, return val of p or q, else return null as in path to node
        // if we get values from both left and right nodes, then current node is LCA

        if (root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;
        else if (right == nullptr) return left;
        else return root; // both not null => LCA found, continue returning till top
    }
};