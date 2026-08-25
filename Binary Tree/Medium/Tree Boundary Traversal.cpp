// Time: O(n) & Space: O(n)
class Solution {
    bool isleaf(Node *node){
        return node && !node->left && !node->right;
    }
    
    void addLeftBoundary(Node *root, vector<int> &res){
        if (!root) return;
        Node* curr = root->left;
        while(curr){
            if(!isleaf(curr)) res.push_back(curr->data);
            if(curr->left){
                curr = curr->left;
            } else{
                curr = curr->right;
            }
        }
    }
    
    void addRightBoundary(Node *root, vector<int> &res){
        if (!root) return;
        Node* curr = root->right;
        stack<int> st;
        while(curr){
            if(!isleaf(curr)) st.push(curr->data);
            if(curr->right){
                curr = curr->right;
            } else{
                curr = curr->left;
            }
        }
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
    }
    
    void addLeaves(Node *node, vector<int> &res){
        if (!node) return;
        if(isleaf(node)){
            res.push_back(node->data);
            return;
        }
        if(node->left) addLeaves(node->left, res);
        if(node->right) addLeaves(node->right, res);
    }
    
public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        
        if(!isleaf(root)){
            res.push_back(root->data);
        }
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};