// Recursive
class Solution {
    void preorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

// Iterative 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            root = st.top(); st.pop();
            preorder.push_back(root->val);
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        return preorder;
    }
};
