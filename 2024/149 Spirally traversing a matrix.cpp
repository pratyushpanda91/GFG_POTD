class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> result;
        int n = mat.size();      // Number of rows
        int m = mat[0].size();   // Number of columns
        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row
            for (int i = left; i <= right; i++) 
                result.push_back(mat[top][i]);
            top++;

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) 
                result.push_back(mat[i][right]);
            right--;

            if (top <= bottom) {
                // Traverse from right to left across the bottom row
                for (int i = right; i >= left; i--) 
                    result.push_back(mat[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                // Traverse from bottom to top along the left column
                for (int i = bottom; i >= top; i--) 
                    result.push_back(mat[i][left]);
                left++;
            }
        }

        return result;
    }
};
