// Time Complexity: O(N * M * 26) where N is the number of words in the wordList and M is the length of each word. For each word, we are trying to change each character (M) to 26 possible characters (a-z).
// Space Complexity: O(N) for the queue and the unordered_set.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);

        while(!q.empty()){
            auto [word, steps] = q.front(); q.pop();
            if(word == endWord) return steps;

            for(int i = 0; i < word.size(); i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};