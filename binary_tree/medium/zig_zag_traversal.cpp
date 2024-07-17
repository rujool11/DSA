// Leetcode 103. zig zag traversal in binary tree

// same as level order traversal, but we calculate index of vector "level" based on flag 
// righttoleft, if true, then we should insert elements right to left, 
// thus from the end, thus index is size - 1 - i, and if flag is false, 
// insert element left to right, and thus index is i itself

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (root == nullptr) return ans;

        q.push(root);
        bool righttoleft = false;
        // flag false => L -> R ; flag true => R -> L (flag can also be called rightoleft)
        // switch flag at each level
        while (!q.empty()) {
            
            int size = q.size();
            vector<int> level(size);

            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = righttoleft ? (size - 1 - i) : i;

                level[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // flip flag after level
            righttoleft = !righttoleft;
            ans.push_back(level);

        }

        return ans;
    }
};