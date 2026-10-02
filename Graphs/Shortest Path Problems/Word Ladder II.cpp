class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) {
            return ans; 
        }

        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0;s

        while(!q.empty()){
            vector<string> arr = q.front(); q.pop();

            if(arr.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    wordSet.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = arr.back();

            if(word == endWord){
                if(ans.empty()) ans.push_back(arr);
                else if(ans[0].size() == arr.size()) ans.push_back(arr);
            }

            for(char &c: word){
                char org = c;
                for(char letter = 'a'; letter <= 'z'; letter++){
                    c = letter;
                    if(wordSet.count(word)){
                        arr.push_back(word);
                        q.push(arr);
                        usedOnLevel.push_back(word);
                        arr.pop_back();
                    }
                }
                c = org;
            }
        }
        return ans;
    }
};