// https://www.geeksforgeeks.org/problems/sort-a-stack/1

// Iterative approach using an extra stack -> Time : O(n^2) and Space : O(n)
class Solution {
  public:
    void sortStack(stack<int> &st) {
        stack<int> temp;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            while(!temp.empty() && x > temp.top()){
                st.push(temp.top());
                temp.pop();
            }
            temp.push(x);
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};

// Recursive approach -> Time : O(n^2) and Space : O(n)
class Solution {
  public:
    void insertStack(stack<int> &st, int x){
        if(st.empty() || x >= st.top()){
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        insertStack(st, x);
        st.push(top);
    }
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        sortStack(st);
        insertStack(st, x);
    }
};

