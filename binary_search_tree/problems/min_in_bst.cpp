// GFG min value in BST

class Solution {
  public:
    int minValue(Node* root) {
      
        while (true) {
            if (!root->left) break;
            root = root->left;
        }
        
        return root->data;
    }
};