// Time: O(N) where N is the number of nodes in the binary tree
class Solution {
    bool checkSym(TreeNode* node1, TreeNode* node2){
        if(!node1 || !node2) return node1 == node2;
        if(node1->val != node2->val) return false;
        return checkSym(node1->left, node2->right) && checkSym(node1->right, node2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return !root || checkSym(root->left, root->right);
    }
};