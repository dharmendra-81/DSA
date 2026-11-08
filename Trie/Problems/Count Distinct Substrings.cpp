struct TrieNode {
    TrieNode* links[26];

    TrieNode() {
        for(int i = 0; i < 26; i++) links[i] = nullptr;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }
 };
 
class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size();
        int cnt = 0;
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < n; i++){
            TrieNode* node = root;
            for(int j = i; j < n; j++){
                if(!node->containsKey(s[j])){
                    cnt++;
                    node->put(s[j], new TrieNode());
                }
                node = node->get(s[j]);
            }
        }
        return cnt;
    }
};