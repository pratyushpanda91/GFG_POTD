class Solution {
  public:
    int nCr(int n, int r) {
        // If r > n, return 0 as it's not possible to choose r from n
        if (r > n) return 0;

        // Create a 2D DP array of size (n+1) x (r+1)
        int dp[n + 1][r + 1];

        // Fill the DP table using Pascal's Triangle logic
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= std::min(i, r); j++) {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        return dp[n][r];
    }
};
