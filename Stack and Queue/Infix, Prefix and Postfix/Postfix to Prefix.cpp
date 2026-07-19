class Solution {
  public:
    string postToPre(string s) {
        stack<string> st;
        
        for(char ch: s){
            if(isalnum(ch)) st.push(string(1, ch));
            else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                
                st.push(ch + t2 + t1);
            }
        }
        return st.top();
    }
};