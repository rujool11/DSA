// GFG Predecessor and Successor 
// (in BST)


class Solution
{
    public:
    
    Node* findPre(Node* root, int key) {
        Node* pre = nullptr;
        
        while (root) {
            if (key <= root->key) {
                root = root->left; // go left since key <
            } else {
                pre = root;
                root = root->right;
                // now, explore higher values on right
            }
        }
        
        return pre;
    }
    
    Node* findSuc(Node* root, int key) {
        Node* suc = nullptr;
        
        while (root) {
            if (key >= root->key) {
                root = root->right; // go right since key >
            } else {
                suc = root;
                root = root->left; 
                // key <, so found, now explore smaller values on left
            }
        }
        
        return suc;
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // time -> O(n), space -> O(n) naive solution -> get inorder and find
        // constant space solution -> T(n) = O(H), S(n) = O(1)
        
        pre = findPre(root, key);
        suc = findSuc(root, key);
    }
};



