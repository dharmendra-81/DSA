// Time: O(n) & Space: O(h) where h is the height of the tree
class Solution {
    int maxsum(TreeNode* node, int &ans){
        if(!node) return 0;
        int lsum = max(0, maxsum(node->left, ans));
        int rsum = max(0, maxsum(node->right, ans));
        ans = max(ans, lsum + rsum + node->val);
        return node->val + max(lsum, rsum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxsum(root, ans);
        return ans;
    }
};