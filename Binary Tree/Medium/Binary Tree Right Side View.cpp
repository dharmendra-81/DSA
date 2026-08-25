// Time: O(n) & Space: O(h) where h is the height of the tree
class Solution {
    void helper(TreeNode* node, int level, vector<int> &res){
        if(node == NULL) return;
        if(level == res.size()) res.push_back(node->val);
        helper(node->right, level+1, res);
        helper(node->left, level+1, res);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        helper(root, 0, res);
        return res;
    }
};