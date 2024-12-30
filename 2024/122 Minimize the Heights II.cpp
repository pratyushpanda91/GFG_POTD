// User function template for C++

class Solution {

  public:

    int getMinDiff(vector<int> &arr, int k) {

        // code here

        sort(arr.begin(),arr.end());

        int ans=arr[arr.size()-1]-arr[0];// No change either +k or -k

        int st=arr[0]+k;

        int fi=arr[arr.size()-1]-k;

        for(int i=1;i<arr.size();i++){

            if(arr[i]-k<0)continue;

            int s=min(st,arr[i]-k);

            int f=max(fi,arr[i-1]+k);

            if(f-s>=0)ans=min(ans,f-s);

        }

        return ans;

    }

};
