// Time: O(n), Space: O(h) where h is the height of the tree
class BSTIterator {
    stack<TreeNode*> st;   
    bool reverse = true;

  public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            reverse ? node = node->right : node = node->left;
        }
    }
    
    int next() {
        TreeNode* temp = st.top(); st.pop();
        reverse ? pushAll(temp->left) : pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
  public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next(), j = right.next();
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = left.next();
            else j = right.next();
        }
        return false;
    }
};