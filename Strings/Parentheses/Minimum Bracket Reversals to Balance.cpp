// Using stack
class Solution {
  public:
    int countMinReversals(string s) {
        int n = s.size();
        if(n & 1) return -1;
        
        // Count the number of unbalanced brackets using a stack
        stack<char> st;
        for(char ch: s){
            if(ch == '{') st.push(ch);
            else{
                (!st.empty() && st.top() == '{') ? st.pop() : st.push(ch);
            }
        }
        
        // Count the number of unbalanced opening and closing brackets
        int open = 0, close = 0;
        while(!st.empty()){
            st.top()=='{' ? open++ : close++;
            st.pop();
        }
        return (open+1)/2 + (close+1)/2;
    }
};

// Greedy approach
class Solution {
  public:
    int countMinReversals(string s) {
        int n = s.size();
        if(n & 1) return -1;
        
        int open = 0, close = 0;
        for(char ch: s){
            if(ch == '{') open++;
            else{
                open > 0 ? open-- : close++;
            }
        }
        return (open+1)/2 + (close+1)/2;
    }
};