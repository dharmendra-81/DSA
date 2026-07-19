class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int asteroid: asteroids){
            if(asteroid > 0){
                st.push_back(asteroid);
            }
            else{
                bool destroyed = false;
                while(!st.empty() && st.back() > 0){
                    if(st.back() < abs(asteroid)){
                        st.pop_back();
                        continue;
                    }
                    else if(st.back() > abs(asteroid)){
                        destroyed = true;
                        break;
                    }
                    else{
                        destroyed = true;
                        st.pop_back();
                        break;
                    }
                }
                if(!destroyed) st.push_back(asteroid);
            }
        }
        return st;
    }
};
// Time: O(n) & Space: O(n)