class Solution {
  public:
    int mode = 1e5;
    vector<int> search(string &pat, string &txt) {
        // code here.
        vector<int> ans;
        int txtHash=0, patHash=0;
        int n=txt.size(), m=pat.size();
        
        for(int i=0;i<m;i++){
            txtHash = (txtHash + (txt[i]-96))%mode;
            patHash = (patHash + (pat[i]-96))%mode;
        }
        
        if(txtHash == patHash && txt.substr(0, m)==pat)
            ans.push_back(1);
        
        
        for(int i=m,j=0; i<n; i++,j++){
            txtHash = (txtHash - (txt[j]-96))%mode;
            txtHash = (txtHash + (txt[i]-96))%mode;
            
            if(txtHash == patHash && txt.substr(j+1, m)==pat)
                ans.push_back(j+2);
        }
        
        return ans;
    }
};
