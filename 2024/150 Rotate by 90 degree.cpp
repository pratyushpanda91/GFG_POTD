class Solution {
  public:
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // Reverse the columns
        for (int j = 0; j < n; j++) {
            for (int i = 0, k = n - 1; i < k; i++, k--) {
                swap(mat[i][j], mat[k][j]);
            }
        }
    }
};
