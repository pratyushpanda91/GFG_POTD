class Solution {
  public:
    unordered_map<Node*, Node*> store;
    unordered_map<Node*, bool> visited;
    unordered_map<Node*, bool> vis2;
    
    void storeFun(Node* n){
        store[n] = new Node(n->val);
        visited[n] = true;
        for(auto z : n->neighbors){
            if(!visited[z])
                storeFun(z);
        }
        return;
    }
    
    void clone(Node* n){
        vis2[n] = true;
        for(auto z : n->neighbors){
            store[n]->neighbors.push_back(store[z]);
            if(!vis2[z])
                clone(z);
        }
        return;
    }
    
  
    Node* cloneGraph(Node* node) {
        // code here
        if(!node)
            return NULL;
        storeFun(node);
        clone(node);
        return store[node];
    }
};
