//  Brute Force
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;

        for(int i = 0; i < s.size(); i++){
            vector<int> hash(26, 0);
            int maxf = 0;
            for(int j = i; j < s.size(); j++){
                hash[s[j] - 'A']++;
                maxf = max(maxf, hash[s[j] - 'A']);
                int changes = (j-i+1) - maxf;
                if(changes <= k){
                    maxlen = max(maxlen, j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};

//  Better => O(n+n)x26
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0, maxlen = 0;
        int left = 0, right = 0;
        vector<int> hash(26, 0);

        while(right < s.size()){
            hash[s[right] - 'A']++;
            maxf = max(maxf, hash[s[right] - 'A']);

            while((right-left+1) - maxf  > k){
                hash[s[left] - 'A']--;
                maxf = 0;
                for(int i = 0; i < 26; i++) 
                    maxf = max(maxf, hash[i]);
                left++;
            }

            if((right-left+1) - maxf <= k){
                maxlen = max(maxlen, right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};

//  Optimal => O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0, maxlen = 0;
        int left = 0, right = 0;
        vector<int> hash(26, 0);

        while(right < s.size()){
            hash[s[right] - 'A']++;
            maxf = max(maxf, hash[s[right] - 'A']);

            if((right-left+1) - maxf  > k){
                hash[s[left] - 'A']--;
                maxf = 0;
                left++;
            }

            if((right-left+1) - maxf <= k){
                maxlen = max(maxlen, right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};