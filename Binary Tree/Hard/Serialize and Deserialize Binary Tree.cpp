class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            if(!node) s += "X,";
            else{
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data);
        string s;
        getline(ss, s, ',');

        TreeNode* root = new TreeNode(stoi(s));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            
            getline(ss, s, ',');
            if(s == "X") node->left = NULL;
            else{
                TreeNode* leftNode = new TreeNode(stoi(s));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(ss, s, ',');
            if(s == "X") node->right = NULL;
            else{
                TreeNode* rightNode = new TreeNode(stoi(s));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
