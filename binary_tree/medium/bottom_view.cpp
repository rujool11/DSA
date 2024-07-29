// GFG Bottom view binary tree

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // similar to top, except update map with every line instance
        vector<int> res;
        if (!root) return res;
        
        queue<pair<Node*, int>> q;
        map<int,int> hash;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            Node* node = p.first;
            int line = p.second;
            
            hash[line] = node->data;
            // update line with node value at every node, because we want the bottom most one
            
            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
            
        }
        
        for (auto it: hash) {
            res.push_back(it.second);
        }
        
        return res;
    }
};