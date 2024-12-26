class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> hashMap;

        for (int num : arr) {
            int complement = target - num;
            if (hashMap.count(complement)) {
                return true; // Pair found
            }
            hashMap[num] = 1; // Add the current number to the map
        }
        return false; // No pair found
    }
};
