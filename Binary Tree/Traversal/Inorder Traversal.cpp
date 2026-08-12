// Recursive
class Solution {
    void inorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

// Iterative
lass Solution {  
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node){
                st.push(node);
                node = node->left;
            } 
            else{
                if(st.empty()) break;
                node = st.top(); st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};