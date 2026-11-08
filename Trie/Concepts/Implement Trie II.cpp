// Time Complexity: O(n) for insert, search and startsWith where n is the length of the word or prefix
struct TrieNode {
    TrieNode* links[26];
    int endWith;
    int prefix;

    TrieNode() {
        for(int i = 0; i < 26; i++) links[i] = nullptr;
        endWith = 0;
        prefix = 0;
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

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->put(c, new TrieNode());
            }
            node = node->get(c);
            node->prefix++;          
        }
        node->endWith++;             
    }

    int countWordsEqualTo(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                return 0;
            }
            node = node->get(c);
        }
        return node->endWith;
    }

    int countWordsStartingWith(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                return 0;
            }
            node = node->get(c);
        }
        return node->prefix;
    }

    void erase(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                return;              
            }
            node = node->get(c);
            node->prefix--;          
        }
        node->endWith--;             
    }
};
