class Solution {
  public:
    string preToPost(string &s) {
        stack<string> st;
        int n = s.size();
        
        for(int i = n-1; i >= 0; i--){
            char ch = s[i];
            
            if(isalnum(ch)) st.push(string(1, ch));
            else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                
                st.push(t1 + t2 + ch);
            }
        }
        return st.top();
    }
};