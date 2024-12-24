class Solution {
public:
    // Function to search a given number in a strictly sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m; // Mapping 1D index to 2D row
            int col = mid % m; // Mapping 1D index to 2D column

            if (mat[row][col] == x) {
                return true; // Element found
            } else if (mat[row][col] < x) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
        return false; // Element not found
    }
};
