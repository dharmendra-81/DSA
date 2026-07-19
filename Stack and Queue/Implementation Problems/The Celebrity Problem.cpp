// using two arrays => Time: O(n^2) and Space: O(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> knowMe(n, 0), IKnow(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    knowMe[j]++;
                    IKnow[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (knowMe[i] == n - 1 && IKnow[i] == 0) {
                return i;
            }
        }
        return -1;
    }
}; 

// using stack => Time: O(n) and Space: O(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        while (st.size() > 1) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (mat[a][b] == 1) {
                st.push(b);
            } else {
                st.push(a);
            }
        }

        int candidate = st.top();
        st.pop();

        // Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
                return -1;
            }
        }

        return candidate;
    }
};

// using two pointers => Time: O(n) and Space: O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n-1;
        
        while(top < down){
            if(mat[top][down]) top++;
            else if(mat[down][top]) down--;
            else{
                top++;
                down--;
            }
        }
        
        if(top > down) return -1;
        int candidate = top;

        // Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
                return -1;
            }
        }

        return candidate;
    }
};