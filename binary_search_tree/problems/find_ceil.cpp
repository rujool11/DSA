// GFG find ceil in BST
// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil = -1;
    
    while (root) {
        if (root->data == input) {
            ceil = root->data;
            break;
        }
        
        if (input > root->data) {
            root = root->right;
        }
        
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    
    return ceil;
}