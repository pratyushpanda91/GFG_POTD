class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
       int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            int mx=max(arr[n-1]-k,arr[i]+k);
            int mn=min(arr[i+1]-k,arr[0]+k);
            ans=min(ans,abs(mx-mn));
        }
        return ans;
    }
};