// GFG Burning Tree

class Solution {
  public:
    
    void getParents(Node* root, unordered_map<Node*, Node*>& parents) {
        
        if (!root) return;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* curr = q.front();
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
    
    Node* getTarget(Node* root, int target) {
        
        // first check left, if exists, return it, else return right Value
        
        if (root == nullptr || root->data == target) return root;
        
        Node* leftRes = getTarget(root->left, target);
        if (leftRes) return leftRes;
        
        return getTarget(root->right, target);
    }
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parents;
        getParents(root, parents);
        
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        
        Node* targetNode = getTarget(root, target);
        if (!targetNode) return 0;
        q.push(targetNode);
        
        visited[targetNode] = true;
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;
            
            for (int i=0; i<size; i++) {
                Node* curr = q.front();
                q.pop();
               
                
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    flag = true;
                }
                
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    flag = true;
                }
                
                if (parents[curr] && !visited[parents[curr]]) {
                    q.push(parents[curr]);
                    visited[parents[curr]] = true;
                    flag = true;
                }
                
                
            }
            
            if (flag) time++;
        }
        
        return time;
        
        
    }
};