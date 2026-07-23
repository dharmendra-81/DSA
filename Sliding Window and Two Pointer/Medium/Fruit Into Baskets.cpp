//  Brute force
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0;

        for(int i = 0; i < fruits.size(); i++){
            set<int> st;
            for(int j = i; j < fruits.size(); j++){
                st.insert(fruits[j]);
                if(st.size() <= 2){
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

// Better
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0;
        int left = 0, right = 0;
        map<int, int> mp;

        while(right < fruits.size()){
            mp[fruits[right]]++;
            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }

            if(mp.size() <= 2) maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};
