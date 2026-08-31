class Solution {
    bool isValidBSThelper(TreeNode* root, pair<long long, long long> limit) {
        if(!root) return true;
        if(limit.first >= root->val || limit.second <= root->val){
            return false;
        }
        return isValidBSThelper(root->left, {limit.first, root->val})
        && isValidBSThelper(root->right, {root->val, limit.second});
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSThelper(root, {LLONG_MIN, LLONG_MAX});
    }
};