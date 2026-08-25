// Time: O(n) & Space: O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); q.pop();
                int ind = leftToRight ? i : (n-1-i);
                level[ind] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            res.push_back(level);
        }
        return res;
    }
};