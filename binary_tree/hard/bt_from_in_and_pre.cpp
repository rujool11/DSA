// Leetcode 105. Construct binary tree from preorder and inorder traversal 

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> inorderHash;
        for (int i=0; i<inorder.size(); i++) {
            inorderHash[inorder[i]] = i; 
        }

        return buildTreeMain(preorder, 0, preorder.size()-1, 
                      inorder, 0, inorder.size()-1, inorderHash);
        
    }

    TreeNode *buildTreeMain(vector<int> &preorder, int preStart, int preEnd,
                            vector<int> &inorder, int inStart, int inEnd,
                            unordered_map<int, int> &inorderHash)
    {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorderHash[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeMain(preorder, preStart + 1, preStart + numsLeft,
                                            inorder, inStart, inRoot - 1, 
                                            inorderHash);

        root->right = buildTreeMain(preorder, preStart + numsLeft + 1, preEnd,
                                            inorder, inRoot + 1, inEnd, 
                                            inorderHash);


        return root;
    }

};