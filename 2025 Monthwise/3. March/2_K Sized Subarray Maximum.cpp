class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        // code here
       vector<int> ans;
        map<int,int>mp;
        int i = 0;int j = 0;
        int n = nums.size();
        while(i<n && j<n)
        {
            mp[nums[j]]++;
            if(j-i+1 ==k)
            {
                auto it = *mp.rbegin();
                ans.push_back(it.first);
                mp[nums[i]]--;
                if(mp[nums[i]] ==  0)
                mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
