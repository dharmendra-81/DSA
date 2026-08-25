// Time: O(N) where N is the number of nodes in the tree
// Space: O(N) for the queue and the map
class Solution {
    void markParents(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*> &parents){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->left){
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parents[node->right] = node;
                q.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        markParents(root, target, parents);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int level = 0;
        
        while(!q.empty()){
            int n = q.size();
            if(level++ == k) break;

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                } 
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                } 
                if(parents[node] && !visited[parents[node]]){
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                } 
            }
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};