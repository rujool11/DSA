// GFG find largest BST in given BT
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue{
public:
    int minVal, maxVal, maxSize; 
    
    NodeValue(int x, int y, int z) {
        this->minVal = x;
        this->maxVal = y;
        this->maxSize = z;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue largestBSTHelper(Node* root) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);
        
        // Postorder
        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);
        
        if (left.maxVal < root->data && right.minVal > root->data) {
            // is a BST
            return NodeValue(min(root->data, left.minVal),
                            max(root->data, right.maxVal),
                            left.maxSize + right.maxSize + 1);
        }
        
        // else condition 
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    int largestBst(Node *root)
    {
    	//linear time, constant space
    	return largestBSTHelper(root).maxSize;
    }
};