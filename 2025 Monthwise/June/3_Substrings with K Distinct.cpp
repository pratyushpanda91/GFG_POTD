class Solution {
public:
    int atMostK(string& s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int left = 0, right = 0, count = 0, distinct = 0;

        while (right < n) {
            if (freq[s[right] - 'a'] == 0) distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) distinct--;
                left++;
            }

            count += right - left + 1;
            right++;
        }

        return count;
    }

    int countSubstr(string& s, int k) {
        if (k == 0) return 0;
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
