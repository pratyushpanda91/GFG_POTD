class Solution {
  public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    vector<int> computeLPS(string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);  // LPS array
        int len = 0;  // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // Fall back to previous prefix
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Function to search for the pattern in the text using KMP algorithm
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int n = txt.size();
        int m = pat.size();

        // Compute the LPS array for the pattern
        vector<int> lps = computeLPS(pat);
        int i = 0;  // Index for txt
        int j = 0;  // Index for pat

        // Search for the pattern in the text
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j);  // Pattern found, add index to result
                j = lps[j - 1];  // Use LPS array to skip unnecessary comparisons
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];  // Fall back to previous LPS
                } else {
                    i++;  // Move to the next character in text
                }
            }
        }

        return result;  // Return all the indices where the pattern is found
    }
};
