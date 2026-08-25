// Inorder Traversal of a Binary Tree using Morris Traversal: O(n) time and O(1) space
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;

        while(cur){
            if(!cur->left){
                inorder.push_back(cur->val);
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
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};

// Preorder Traversal of a Binary Tree using Morris Traversal: O(n) time and O(1) space
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while(cur){
            if(!cur->left){
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* predecessor = cur->left;

                while(predecessor->right && predecessor->right != cur){
                    predecessor = predecessor->right;
                }

                if(!predecessor->right){
                    predecessor->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    predecessor->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};

