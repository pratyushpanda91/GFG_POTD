class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int>prev(1,1);
        if(n==1)
        {
            return prev;
        }
        vector<int>curr;
        for(int i=2;i<=n;i++)
        {
            curr.resize(i);
            curr[0]=1;
            curr[i-1]=1;
            for(int j=1;j<i-1;j++)
            {
                curr[j]=prev[j-1]+prev[j];
            }
            prev=curr;
        }
        return prev;
    }
};
