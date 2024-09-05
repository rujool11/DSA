// Leetcode 230. Kth smallest element in BST
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

    void inOrder(TreeNode* root, vector<int>& vec) {
        if (!root) return;

        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inOrder(root, inorder);
        return inorder[k-1];
    }
};

//----------------------------------------------------------------------------------------------------------
// No extra space solution ->

class Solution {
public:

    void inorderHelper(TreeNode* root, int k, int& returnable, int& count) {
        if (!root) return;

        inorderHelper(root->left, k, returnable, count);

        count++; 
        if (count == k) {
            returnable = root->val;
            return;
        }

        inorderHelper(root->right, k, returnable, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int returnable = 0;
        int count = 0;
        inorderHelper(root, k, returnable, count);
        return returnable;
    }
};