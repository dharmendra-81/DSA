// Time Complexity: O(n) for insert, search and startsWith where n is the length of the word or prefix
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
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c: word){
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return node->flag; 
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c: prefix){
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return true;       
    }
};
