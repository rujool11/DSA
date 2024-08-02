// GFG parent val = child sum property check 

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool isLeaf(Node* root) {
        return (root && !root->left && !root->right);
    }
    
    int isSumProperty(Node *root)
    {   
        if (root == nullptr) return 1;
        int left_val = isSumProperty(root->left);
        int right_val = isSumProperty(root->right);
        if (!left_val || !right_val) return 0;
        int sum = 0;
        if (root->left) sum += root->left->data;
        if (root->right) sum += root->right->data;
        if (isLeaf(root) || sum == root->data) return 1;
    }
};