class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int>vis(n+1,0);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        int ans = -1;
        int curr = 0;
        while(!q.empty()){
            bool f = true;
            int siz = q.size();
            for(int x = 0;x < siz;x++){
                int node = q.front();
                q.pop();
                if(node == n-1){
                    ans = curr;
                    f = false;
                    break;
                }
                for(int i=node+1;i<=node+arr[node];i++){
                    if(i < n and vis[i] == 0){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
            if(f == false)break;
            curr++;
        }
        return ans;
    }
};
