class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int result = -1;

        while (root != nullptr) {
            if (root->data == k) {
                return k; // exact match
            }
            if (root->data < k) {
                result = root->data; // candidate
                root = root->right;
            } else {
                root = root->left;
            }
        }

        return result;
    }
};
