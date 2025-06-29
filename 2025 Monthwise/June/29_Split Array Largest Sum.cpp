class Solution {
    private:
    /* Function to count partitions such 
    that each partition has sum <= maxSum*/
    int countPartitions(vector<int> arr, int maxSum) {
        int n = arr.size();
        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < n; i++) {
            if (subarraySum + arr[i] <= maxSum) {
                // Add element to the current subarray
                subarraySum += arr[i];
            } else {
                // Start a new subarray with current element
                partitions++;
                subarraySum = arr[i];
            }
        }

        return partitions;
    }
  public:
    int splitArray(vector<int>& arr, int k) {
             // Initialize binary search boundaries
        int low = *max_element(arr.begin(), arr.end()); 
        int high = accumulate(arr.begin(), arr.end(), 0);

        // Apply binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(arr, mid);

            if (partitions > k) {
                /*If partitions exceed k, increase 
                the minimum possible subarray sum*/
                low = mid + 1;
            } 
            else {
                /*If partitions are within k, try to
                minimize the subarray sum further*/
                high = mid - 1;
            }
        }

        /* After binary search, 'low' will 
        be the largest minimum subarray sum
        with at most k partitions*/
        return low;  // code here
        
    }
};
