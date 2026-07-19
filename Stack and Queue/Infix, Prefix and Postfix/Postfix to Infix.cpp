class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string> st;
        
        for(char ch: exp){
            if(isalnum(ch)) st.push(string(1, ch));
            else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                st.push('(' + t2 + ch + t1 + ')');
            }
        }
        return st.top();
    }
};
