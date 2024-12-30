class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> freqMap; // To store the frequency of elements
        int count = 0;

        for (int num : arr) {
            int complement = target - num; // Find the complement
            if (freqMap[complement] > 0) { // Check if complement exists in map
                count += freqMap[complement]; // Add the frequency of complement to count
            }
            freqMap[num]++; // Update frequency of the current number
        }

        return count;
    }
};
