// Leetcode 863. All Nodes Distance K in binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS to get parents of all nodes in a hash
// then, find target and BFS radially to get nodes at a particular distance
// keep visited hash to ensure we dont get back to parent (eg. 2->5->2 (when going back up))
class Solution {
public:

    void get_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            
            if (curr->right) {
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        get_parents(root, parents);

        unordered_map<TreeNode*, bool> visited; // visited nodes in 2nd BFS
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();
            if (distance++ == k) break;

            // inner for loop used so that nodes at a particular distance can be processed
            // similar to level order when nodes at a particular level need to be processed
            // else, we will mix nodes at different distances/ levels
            for (int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if (parents[curr] && !visited[parents[curr]]) {
                    q.push(parents[curr]);
                    visited[parents[curr]] = true;
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};