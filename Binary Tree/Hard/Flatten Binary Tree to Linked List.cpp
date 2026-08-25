// Recursive approach: O(n) time and O(h) space
class Solution {
    TreeNode* prev;

public:
    void flatten(TreeNode* node) {
        if(!node) return;

        flatten(node->right);
        flatten(node->left);

        node->right = prev;
        node->left = NULL;
        prev = node;
    }
};

// Iterative approach: O(n) time and O(h) space
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* cur = st.top(); st.pop();

            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);

            if(!st.empty()) cur->right = st.top();
            cur->left = NULL;
        }
    }
};

// Morris traversal approach: O(n) time and O(1) space
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* cur = root;

        while(cur){
            if(cur->left){
                TreeNode* prev = cur->left;

                while(prev->right){
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};