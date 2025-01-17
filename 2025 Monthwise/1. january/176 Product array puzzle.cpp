class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> l_prod(n+2,1),r_prod(n+2,1),ans(n,1);
        for(int i = 0;i < n;i++){
            l_prod[i+1] = l_prod[i]*arr[i];
            r_prod[n-i] = r_prod[n-i+1]*arr[n-1-i];
        }
        for(int i = 0; i < n;i++)
            ans[i] = l_prod[i]*r_prod[i+2];
        return ans;
    }
};
