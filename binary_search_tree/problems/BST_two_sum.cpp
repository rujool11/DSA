// Leetcode 653. Two Sum IV - Input is a BST

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

    void getInorder(TreeNode* root, vector<int>& vec) {
        if (!root) return;

        getInorder(root->left, vec);
        vec.push_back(root->val);
        getInorder(root->right, vec);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        getInorder(root, inorder);

        int left = 0;
        int right = inorder.size()-1; 
        // 2 ptrs since sorted

        while (left < right) {
            if (inorder[left] + inorder[right] < k) left++;
            else if (inorder[left] + inorder[right] > k) right--;
            else return true;
        }

        return false;
    }
};

// -----------------------------------------------------------------------------------------------------
// Space optimized (Optimal) ->
// use next/before as in BST iterator

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

class BSTIterator {
    stack<TreeNode*> st;
    bool isReverse = false; // if we want before, set this to true

public:
    BSTIterator(TreeNode* root, bool reverse) {
        isReverse = reverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if (!isReverse) pushAll(curr->right);
        else pushAll(curr->left);
        return curr->val;
    }

private:
    void pushAll(TreeNode* curr) {
        while (curr) {
            st.push(curr);
            if (!isReverse) curr = curr->left;
            else curr = curr->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       // space optimized solution (optimal) ->

        if (!root) return false;
        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = left.next();
            else j = right.next();
        }

        return false;
    }
};
