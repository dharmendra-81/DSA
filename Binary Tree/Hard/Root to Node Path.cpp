class Solution{
    public:
    bool getPath(TreeNode* root, vector<int>& path, int target) {
        if (!root) return false;
        
        path.push_back(root->val);
        
        if (root->val == target) return true;
        
        if (getPath(root->left, path, target) || getPath(root->right, path, target)) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    vector<int> rootToNodePath(TreeNode* root, int target) {
        vector<int> path;
        if (getPath(root, path, target)) {
            return path;
        }
        return {};
    }
};