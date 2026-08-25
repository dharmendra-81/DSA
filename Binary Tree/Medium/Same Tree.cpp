// Time: O(n) & Space: O(h) where h is the height of the tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(!p || !q) return p == q;
       return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }
};