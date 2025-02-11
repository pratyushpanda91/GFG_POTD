class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return isBST(root, INT_MIN, INT_MAX);
    }
    bool isBST(Node *root, long min_val , long max_val)
    {
        if(root==NULL)
        return true;
        if(root->data>=max_val || root->data<=min_val)
        return false;
        return isBST(root->left , min_val , root->data)
        && isBST(root->right , root->data, max_val);
    }
};
