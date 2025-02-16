class Solution
{
    public:
    void in (Node* root,vector<int>&ans){
        if(!root) return ;
        in(root->left,ans);
        ans.push_back(root->data);
        in(root->right,ans);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int>ans; 
        in(root,ans);
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
       return NULL;
    }

};
