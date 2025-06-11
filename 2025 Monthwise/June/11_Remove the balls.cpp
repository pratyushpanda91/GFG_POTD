class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int, int>> st;
        int n = color.size();

        for (int i = 0; i < n; ++i) {
            if (!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) {
                // Same color and radius -> remove pair
                st.pop();
            } else {
                st.push({color[i], radius[i]});
            }
        }

        return st.size();  // Remaining balls
    }
};
