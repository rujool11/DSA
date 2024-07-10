// Leetcode 102. Binary Tree Level Order Traversal


// queue used for this 
// FIFO -> push from back, pop from front
// add root to queue
// while q is not empty -> 
// get size of q (necessary to avoid confusion due to dynamic q size)
// keep level array for each level 
// for loop from  0 to size -> 
// set node to front of q, and pop front
// push left and right children, if they exist, to q 
// push value of node to level 
// push level to ans

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            
            int size = q.size(); // use size var because q is modified, so size shouldnt change
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // to be popped next
                q.pop(); // pop out

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->val);
            }

            ans.push_back(level);

        }

        return ans;
    }
};