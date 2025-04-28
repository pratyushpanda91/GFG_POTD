// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Helper function that returns a pair of integers
    // First element: maximum sum including current node
    // Second element: maximum sum excluding current node
    pair<int, int> solve(Node* root) {
        if (!root)
            return {0, 0};
        
        // Recurse for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        // If we include current node, we cannot include its children
        int include = root->data + left.second + right.second;
        
        // If we exclude current node, we can take maximum of including or excluding its children
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }

    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};
