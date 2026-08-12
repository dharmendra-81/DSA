// Time: O(n) & Space: O(n)
class Solution {
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(rh - lh) > 1) return -1;
        return 1 + max(lh, rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
};