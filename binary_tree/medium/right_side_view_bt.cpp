// Leetcode 199. Binary Tree right side view

// naive solution -> levelorder, and then take the rightmost of every level

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> levelorder;
        vector<int> res;

        if (!root) return res;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->val); 
            }

            levelorder.push_back(level);
        }

        for (int i=0; i<levelorder.size(); i++) {
            res.push_back(levelorder[i][levelorder[i].size() - 1]);
        }

        return res;
    }
};

// Recursive solution (very short and simple code) -> 

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
    void helper(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (res.size() == level) res.push_back(root->val); // add first node from right side always 
        helper(root->right, level+1, res);
        helper(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        // recursive solution -> reverse preorder traversal (Root-> R -> L)
        // since fisrt Right one is part of right view

        vector<int> res;
        helper(root, 0, res);
        return res;
    }
};

