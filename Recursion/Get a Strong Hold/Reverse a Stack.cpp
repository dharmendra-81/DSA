// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

// using extra stack -> Time complexity: O(n), space complexity: O(n)
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        stack<int> temp;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            temp.push(x);
        }
        st = temp;
    }
};

// using recursion -> Time complexity: O(n^2), space complexity: O(n)
class Solution {
  public:
    void insertStack(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        insertStack(st, x);
        st.push(top);
    }

    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        reverseStack(st);
        insertStack(st, x);
    }
};