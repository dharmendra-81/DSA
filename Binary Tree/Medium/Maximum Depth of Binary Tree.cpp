// Recursive
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l, r);
    }
};

// Level Order Traversal
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};