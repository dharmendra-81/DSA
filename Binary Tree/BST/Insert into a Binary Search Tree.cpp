// Time: O(h) where h is the height of the tree
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(!root) return new TreeNode(x);
        TreeNode* cur = root;

        while(true){
            if(x >= cur->val){
                if(cur->right) cur = cur->right;
                else{
                    cur->right = new TreeNode(x);
                    break;
                }
            }
            
            else{
                if(cur->left) cur = cur->left;
                else{
                    cur->left = new TreeNode(x);
                    break;
                }
            }
        }
        return root;
    }
};