// GFG binary tree top view

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.

    vector<int> topView(Node *root) {
        // use level order traversal since it gives the top nodes first
        vector<int> res;
        if (root == nullptr) return res;

        queue<pair<Node *, int>> q; // (node, line)
        map<int, int> hash; // (node -> value)
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            Node *curr = p.first;
            int line = p.second;

            if (hash.find(line) == hash.end()) hash[line] = curr->data;
            // if no node value corresponding to line, add current node value
            // since only top position required from one line, add first one

            if (curr->left) q.push({curr->left, line - 1});
            if (curr->right) q.push({curr->right, line + 1});
        }

        for (auto it : hash) {
            res.push_back(it.second); // map, so ordered by key
        }

        return res;
    }
};
