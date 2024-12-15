class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check if mid is a peak
            if (arr[mid] > arr[mid + 1]) {
                // Move to the left half if the left neighbor is greater
                high = mid;
            } else {
                // Move to the right half
                low = mid + 1;
            }
        }
        return low; // or return high, as low == high at the end
    }
};
