struct TrieNode {
    TrieNode* links[2];

    TrieNode() {
        for(int i = 0; i < 2; i++) links[i] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    TrieNode* get(int bit) {
        return links[bit];
    }

    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }
 };

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num) {
        TrieNode* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum = (1 << i) | maxNum; 
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> offlineQueries;
        int q = queries.size();

        for(int i = 0; i < q; i++){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(q, 0);
        int ind = 0;
        int n = nums.size();
        Trie trie;

        for(auto &[mi, p]: offlineQueries){
            auto [xi, qi] = p;

            while(ind < n && nums[ind] <= mi){
                trie.insert(nums[ind]);
                ind++;
            }

            ans[qi] = (ind == 0) ? -1 : trie.getMax(xi);
        }
        return ans;
    }
};