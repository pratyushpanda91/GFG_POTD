class Solution {
  public:
    // Function to check if cows can be placed with a minimum distance 'mid'
    bool canPlaceCows(vector<int> &stalls, int k, int mid) {
        int cowsPlaced = 1; // Place the first cow in the first stall
        int lastPosition = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= mid) {
                cowsPlaced++;
                lastPosition = stalls[i];
            }
            if (cowsPlaced >= k) return true; // If all cows are placed successfully
        }
        return false;
    }

    // Function to find the maximum minimum distance
    int aggressiveCows(vector<int> &stalls, int k) {
        // Step 1: Sort the stall positions
        sort(stalls.begin(), stalls.end());

        // Step 2: Initialize binary search range
        int low = 1, high = stalls.back() - stalls[0];
        int result = 0;

        // Step 3: Binary Search to find the optimal distance
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                result = mid;   // Update result and search for a larger distance
                low = mid + 1;
            } else {
                high = mid - 1; // Search for a smaller distance
            }
        }
        return result;
    }
};
