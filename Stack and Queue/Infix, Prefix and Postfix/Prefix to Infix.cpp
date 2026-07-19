class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        int n = pre_exp.size();
        
        for(int i = n-1; i >= 0; i--){
            char ch = pre_exp[i];
            
            if(isalnum(ch)) st.push(string(1, ch));
            else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                
                st.push('(' + t1 + ch + t2 + ')');
            }
        }
        return st.top();
    }
};