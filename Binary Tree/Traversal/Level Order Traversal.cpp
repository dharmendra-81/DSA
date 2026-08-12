class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int n = q.size();

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            res.push_back(level);
        }
        return res;
    }
};