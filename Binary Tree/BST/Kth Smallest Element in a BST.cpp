// Time Complexity: O(n) & Space Complexity: O(1) (Morris Traversal)
class Solution {
    void inorderTraversal(TreeNode* root, int &res, int k) {
        int cnt = 0;
        TreeNode* cur = root;

        while(cur){
            if(!cur->left){
                cnt++;
                if(cnt == k) res = cur->val;
                cur = cur->right;
            }
            else{
                TreeNode* predecessor = cur->left;

                while(predecessor->right && predecessor->right != cur){
                    predecessor = predecessor->right;
                }

                if(!predecessor->right){
                    predecessor->right = cur;
                    cur = cur->left;
                }
                else{
                    predecessor->right = NULL;
                    cnt++;
                    if(cnt == k) res = cur->val;
                    cur = cur->right;
                }
            }
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        inorderTraversal(root, res, k);
        return res;
    }
};