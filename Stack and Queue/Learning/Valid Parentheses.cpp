class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char prev = st.top();
                st.pop();
                if((ch == ')' && prev == '(') ||
                (ch == ']' && prev == '[') ||
                (ch == '}' && prev == '{')){
                    continue;
                }
                else return false;
            }
        }
        return st.empty();
    }
};