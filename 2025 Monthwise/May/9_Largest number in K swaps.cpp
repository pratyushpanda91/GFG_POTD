class Solution {
  public:
    string maxNum;

    void findMaximum(string &s, int k, int idx) {
        if (k == 0)
            return;

        int n = s.length();
        char maxDigit = s[idx];

        // Find the maximum digit from idx to end
        for (int i = idx + 1; i < n; i++) {
            if (s[i] > maxDigit)
                maxDigit = s[i];
        }

        // Only proceed if there's a better digit to swap with
        if (maxDigit != s[idx])
            k--;

        for (int i = n - 1; i >= idx; i--) {
            if (s[i] == maxDigit) {
                swap(s[i], s[idx]);
                if (s.compare(maxNum) > 0) {
                    maxNum = s;
                }

                findMaximum(s, k, idx + 1);

                // Backtrack
                swap(s[i], s[idx]);
            }
        }
    }

    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        maxNum = s;
        findMaximum(s, k, 0);
        return maxNum;
    }
};
