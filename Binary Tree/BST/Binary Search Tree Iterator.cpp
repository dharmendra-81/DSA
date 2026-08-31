// Time: amortized O(1), Space: O(h) where h is the height of the tree
class BSTIterator {
    stack<TreeNode*> st;    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode* temp = st.top(); st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

