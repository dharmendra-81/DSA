class Solution {
    TreeNode* build(vector<int>& post, int postSt, int postEnd, 
    vector<int>& in, int inSt, int inEnd, unordered_map<int, int> &mp) {
        if(postSt > postEnd || inSt > inEnd) return NULL;

        TreeNode* root = new TreeNode(post[postEnd]);

        int inRoot = mp[root->val];
        int numsLeft = inRoot - inSt;

        root->left = build(post, postSt, postSt+numsLeft-1,
        in, inSt, inRoot-1, mp);
        root->right = build(post, postSt+numsLeft, postEnd-1,
        in, inRoot+1, inEnd, mp);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(postorder, 0, postorder.size()-1,
        inorder, 0, inorder.size()-1, mp);
        return root;
    }
};