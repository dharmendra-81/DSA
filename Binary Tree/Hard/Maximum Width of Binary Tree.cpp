class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            long long minInd = q.front().second;
            int first = 0, last = 0;

            for(int i = 0; i < n; i++){
                long long ind = q.front().second - minInd;
                TreeNode* node = q.front().first; 
                q.pop();
                if(i == 0) first = ind;
                if(i == n-1) last = ind;
                if(node->left) q.push({node->left, ind*2 + 1});
                if(node->right) q.push({node->right, ind*2 + 2});
            }
            maxWidth = max(maxWidth, last-first+1);
        }
        return maxWidth;
    }
};