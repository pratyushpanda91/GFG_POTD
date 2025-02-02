class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                Node* node = q.front();
                q.pop();
                temp.push_back(node->data);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
