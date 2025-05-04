class Solution {
  public:
    int findSubString(string& str) {
        int n = str.size();
        if (n == 0) return 0;

        // Step 1: Count total distinct characters in str
        unordered_set<char> unique_chars(str.begin(), str.end());
        int total_unique = unique_chars.size();

        // Step 2: Sliding window + character count map
        unordered_map<char, int> freq;
        int start = 0, min_len = n + 1;
        int count = 0;

        for (int end = 0; end < n; end++) {
            freq[str[end]]++;

            // Count only when a new unique char is seen
            if (freq[str[end]] == 1) {
                count++;
            }

            // Try to shrink the window from the start
            while (count == total_unique) {
                // Update minimum window length
                min_len = min(min_len, end - start + 1);

                // Shrink from the start
                freq[str[start]]--;
                if (freq[str[start]] == 0) {
                    count--;
                }
                start++;
            }
        }

        return min_len;
    }
};
