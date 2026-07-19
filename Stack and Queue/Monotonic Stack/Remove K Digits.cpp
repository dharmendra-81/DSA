/*
Intuition:
-> keep smaller digits in the stack and remove larger digits from the stack when we encounter a smaller digit.
-> if the stack is empty, we can push the current digit into the stack.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";     // if we need to remove all digits, return "0"
        string st;

        for(char ch: num){
            while(!st.empty() && k && st.back() > ch){
                st.pop_back();
                k--;
            }
            if(!st.empty()) st.push_back(ch);
            else{
                if(ch == '0') continue;     // skip leading zeros
                st.push_back(ch);
            }
        }

        while(k && !st.empty()){    // if we still have digits to remove, remove from the end
            st.pop_back();
            k--;
        }

        return st.empty() ? "0" : st;
    }
};

// Time: O(n) & Space: O(n)