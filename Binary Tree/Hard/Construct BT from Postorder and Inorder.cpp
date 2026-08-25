class Solution {
    TreeNode* build(vector<int>& pre, int preSt, int preEnd, 
    vector<int>& in, int inSt, int inEnd, unordered_map<int, int> &mp) {
        if(preSt > preEnd || inSt > inEnd) return NULL;

        TreeNode* root = new TreeNode(pre[preSt]);

        int inRoot = mp[root->val];
        int numsLeft = inRoot - inSt;

        root->left = build(pre, preSt+1, preSt+numsLeft,
        in, inSt, inRoot-1, mp);
        root->right = build(pre, preSt+numsLeft+1, preEnd,
        in, inRoot+1, inEnd, mp);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, 0, preorder.size()-1,
        inorder, 0, inorder.size()-1, mp);
        return root;
    }
};