// Leetcode 297. serialize and deserialize binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // level order -> null represented by #
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string code = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr) {
                code.append("#,");
                continue;
            }
            
            else code.append(to_string(curr->val) + ",");
            
            q.push(curr->left);
            q.push(curr->right);
        }

        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;

        // use stringstream 
        stringstream code(data);
        string str;
        getline(code, str, ','); // gets str bewteen delimiter in code

        TreeNode* root = new TreeNode(stoi(str)); // stringtointerger -> stoi
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            getline(code, str, ',');
            if (str == "#") curr->left = nullptr;
            else {
                TreeNode* left = new TreeNode(stoi(str));
                curr->left = left;
                q.push(left);
            }

            getline(code, str, ',');
            if (str == "#") curr->right = nullptr;
            else {
                TreeNode* right = new TreeNode(stoi(str));
                curr->right = right;
                q.push(right);
            }

        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));