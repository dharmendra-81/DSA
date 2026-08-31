// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree
class Solution {
    TreeNode *prev, *first, *middle, *last;
public:
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(prev && prev->val > root->val){
            if(!first){
                first = prev;
                middle = root;
            }
            // If this is the second violation, mark last
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root){
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};