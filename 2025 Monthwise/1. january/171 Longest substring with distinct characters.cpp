class Solution {
  public:
    int longestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLength = 0, start = 0;
        
        for (int end = 0; end < s.size(); end++) {
            char ch = s[end];
            // Check if the character is within the current window
            if (lastIndex.find(ch) != lastIndex.end() && lastIndex[ch] >= start) {
                start = lastIndex[ch] + 1;
            }
            // Update the last occurrence of the character
            lastIndex[ch] = end;
            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
