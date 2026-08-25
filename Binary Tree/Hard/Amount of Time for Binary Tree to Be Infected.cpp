class Solution {
    TreeNode* markParents(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &parents){
        TreeNode* time;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->val == start) time = node;

            if(node->left){
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parents[node->right] = node;
                q.push(node->right);
            }
        }
        return time;
    }

    int findMaxDistance(TreeNode* target, unordered_map<TreeNode*, TreeNode*> &parents){
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int time = 0;   
        while(!q.empty()){
            int n = q.size();
            bool flag = false; // to check if any new node is infected in this time unit

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left && !visited[node->left]){
                    flag = true;
                    q.push(node->left);
                    visited[node->left] = true;
                } 
                if(node->right && !visited[node->right]){
                    flag = true;
                    q.push(node->right);
                    visited[node->right] = true;
                } 
                if(parents[node] && !visited[parents[node]]){
                    flag = true;
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                }

            }
            if(flag) time++; 
        }
        return time;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parents;
        TreeNode* target = markParents(root, start, parents);
        int time = findMaxDistance(target, parents);
        return time;
    }
};