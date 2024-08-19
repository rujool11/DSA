// Leetcode 106. construct binary tree from inorder and postorder traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int> inorderHash;
        for (int i=0; i<inorder.size(); i++) {
            inorderHash[inorder[i]] = i;
        }

        TreeNode* root = buildTreeMain(inorder, 0, inorder.size()-1,
                                        postorder, 0, postorder.size()-1,
                                        inorderHash);

        return root;
    }

    TreeNode* buildTreeMain(vector<int>& inorder, int inStart, int inEnd, 
                            vector<int>& postorder, int postStart, int postEnd, 
                            unordered_map<int,int>& inorderHash)
    {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inorderHash[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeMain(inorder, inStart, inRoot - 1,
                                    postorder, postStart, postStart + numsLeft - 1, 
                                    inorderHash);

        root->right = buildTreeMain(inorder, inRoot+1, inEnd,
                                    postorder, postStart + numsLeft, postEnd-1,
                                    inorderHash);

        return root;
    }
};