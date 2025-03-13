class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        // Create a 2D DP table to store the maximum value that can be obtained
        // with first i items and capacity j
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        // Fill the DP table in bottom-up manner
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                // If weight of current item is less than or equal to current capacity w,
                // then we have two options: include the item or exclude it
                if (wt[i-1] <= w) {
                    // Maximum of:
                    // 1. Include the item: value of current item + value of remaining capacity
                    // 2. Exclude the item: value with previous items only
                    dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
                } else {
                    // If the weight of the current item is more than the current capacity,
                    // we can only exclude it
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        // The bottom-right cell contains the maximum value for the given knapsack capacity
        return dp[n][W];
    }
};
