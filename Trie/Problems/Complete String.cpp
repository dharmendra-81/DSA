struct TrieNode {
    TrieNode* links[26];
    bool flag;

    TrieNode() {
        for(int i = 0; i < 26; i++) links[i] = nullptr;
        flag = false;
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

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c: word){
            if (!node->containsKey(c)) {
                node->put(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->flag = true;
    }

    bool checkIfPrefixExists(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) return false;
            node = node->get(c);
            if (!node->flag) return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for(string &s: a) trie.insert(s);

    string longest;
    for(string &s: a){
        if(trie.checkIfPrefixExists(s)){
            if(s.length() > longest.length()){
                longest = s;
            }
            else if(s.length() == longest.length() && s < longest){
                longest = s;
            }
        }
    }
    return longest.empty() ? "None" : longest;
}