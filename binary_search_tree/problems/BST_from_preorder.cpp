// Leetcode 1008. Construct BST from preorder traversal

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

// inorder would just be ascending order
// naive -> traverse through preorder, and just insert in tree using BST insert
// naive T(n) = O(n^2); for every node (O(n)) insert (O(n)) => O(n^2)
// better solution -> O(nlogn) + O(n)
// sort preorder to get inordre and then construct BT using pre and in 
// best solution ->
// validate BST like solution
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);
    }

    TreeNode* buildBST(vector<int>& preorder, int& index, int upper_bound) {
        if (index == preorder.size() || preorder[index] > upper_bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = buildBST(preorder, index, root->val);
        root->right = buildBST(preorder, index, upper_bound);

        return root;
    }
};