class Solution {
    int precedence(char op){
        if(op == '^') return 3;
        if((op == '*') || (op == '/')) return 2;
        if((op == '+') || (op == '-')) return 1;
        return 0;
    }
    
    bool isOperator(char ch){
        return ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-';
    }
    
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans;
        
        for(char ch: s){
            if(isalnum(ch)) ans.push_back(ch);
            else if(ch == '(') st.push(ch);
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove (
            }
            else{
                if(isOperator(ch)){
                    while( !st.empty() && st.top() != '('
                    && ( precedence(ch) < precedence(st.top())
                    || (precedence(ch) == precedence(st.top()) && ch == '^'))){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(ch);
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
   
  public:
    string infixToPrefix(string &s) {
        reverse(s.begin(), s.end());
        
        for(char &ch: s){
            if(ch == '(') ch=')';
            else if(ch == ')') ch='(';
        }
        
        string ans = infixToPostfix(s);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
