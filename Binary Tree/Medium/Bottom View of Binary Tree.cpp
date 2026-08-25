class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto [node, line] = q.front(); q.pop();
            mp[line] = node->data;
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        
        vector<int> ans;
        for(auto it: mp){
           ans.push_back(it.second); 
        }
        return ans;
    }
};