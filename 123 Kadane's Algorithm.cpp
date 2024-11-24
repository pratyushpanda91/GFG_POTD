class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        int maxSum = INT_MIN, currSum = 0;
        
        for(int i = 0; i < n; ++i){
            currSum += arr[i];
            maxSum = max(maxSum, currSum);
            
            if(currSum < 0) currSum = 0;
        }
        
        return maxSum;
    }
};
