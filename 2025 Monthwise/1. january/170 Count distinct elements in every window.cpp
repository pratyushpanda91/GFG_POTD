class Solution {
  public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        vector<int> result;
        unordered_map<int, int> freqMap;
        int n = arr.size();
        
        // Initialize the frequency map for the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }
        result.push_back(freqMap.size());

        // Slide the window over the array
        for (int i = k; i < n; i++) {
            // Remove the element going out of the window
            freqMap[arr[i - k]]--;
            if (freqMap[arr[i - k]] == 0) {
                freqMap.erase(arr[i - k]);
            }

            // Add the new element in the window
            freqMap[arr[i]]++;

            // Record the distinct count
            result.push_back(freqMap.size());
        }

        return result;
    }
};
