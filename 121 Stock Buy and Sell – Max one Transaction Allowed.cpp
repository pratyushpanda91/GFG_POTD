class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int minPrice = INT_MAX; // Track the minimum price so far
        int maxProfit = 0;      // Track the maximum profit

        for (int price : prices) {
            minPrice = min(minPrice, price);           // Update the minimum price
            maxProfit = max(maxProfit, price - minPrice); // Calculate the profit
        }
        return maxProfit;
    }
};
