// Recursive
class Solution {
    void postorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

// Iterative using two stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
           root = st1.top(); st1.pop();
           st2.push(root);
           if(root->left) st1.push(root->left); 
           if(root->right) st1.push(root->right); 
        }

        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        
        return postorder;
    }
};

// Iterative using one stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp) curr = temp;
                else{
                    temp = st.top(); st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top(); st.pop();
                        postorder.push_back(temp->val);
                    }
                }

            }
        }

        return postorder;
    }
};