// Leetcode 662. Maximum width of binary tree

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // maximum nodes in a level between any two nodes

        // use indexing, in any level, max width = rightmost index - leftmost index + 1
        //     root (i)
        //    /         \
        //   (2*i + 1)  (2* i + 2)
        // but, this might lead to an integer overflow (doubling at every level)

        // so, we just start each level from 1
        // at each level, change i to (i - min), where min is mininal value on that level


        queue<pair<TreeNode*,long>> q;
        q.push({root, 0});
        int ans = 0;


        while (!q.empty()) {

            int size = q.size();
            long mmin = q.front().second; // minimal value on that level, to make index start from 0
            long first = 0, last = 0;
            
            for (int i=0; i<size; i++) {
                long curr_idx = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curr_idx;
                else if (i == size - 1) last = curr_idx;
                if (node->left) q.push({node->left, curr_idx*2 + 1});
                if (node->right) q.push({node->right, curr_idx*2 + 2});
            }
            
            ans = max((long) ans, last - first + 1);
        }

        return ans;
    }
};