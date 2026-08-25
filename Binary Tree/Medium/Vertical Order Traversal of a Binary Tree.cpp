// Time: O(n log n) & Space: O(n)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int> >> nodes;
        queue<pair<TreeNode*, pair<int, int> >> todo;
        todo.push({root, {0, 0}});

        while(!todo.empty()){
            auto [node, coords] = todo.front();
            todo.pop();
            
            int col = coords.first;
            int row = coords.second;

            nodes[col][row].insert(node->val);
            if(node->left){
                todo.push({node->left, {col-1, row+1}});
            }
            if(node->right){
                todo.push({node->right, {col+1, row+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto [row, values]: p.second){
                col.insert(col.end(), values.begin(), values.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};