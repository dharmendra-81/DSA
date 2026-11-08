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
                maxNum = (1 << i) | maxNum; // Turn bit
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
    int findMaximumXOR(vector<int>& nums) {
       Trie trie;
       for(int num: nums) trie.insert(num); 

       int ans = 0;
       for(int num: nums){
           ans = max(ans, trie.getMax(num));   
       }
       return ans;
    }
};