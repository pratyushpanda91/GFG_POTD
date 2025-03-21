class Solution {
  public:
    int maxSum(vector<int>&nums){
        int result=INT_MIN;
        int csum=0;
        for(auto&val:nums){
            csum+=val;
            result=max(result,csum);
            if(csum<0)csum=0;
        }
        return result;
    }
    int minSum(vector<int>&nums){
        int result=INT_MAX;
        int csum=0;
        for(auto&val:nums){
            csum+=val;
            result=min(result,csum);
            if(csum>0)csum=0;
        }
        return result;
    }
    int circularSubarraySum(vector<int> &arr) {
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        int maxsum=maxSum(arr);
        int minsum=minSum(arr);
        return max(maxsum,(totalSum-minsum));
    }
};
