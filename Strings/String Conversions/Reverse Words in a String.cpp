// Using stringstream
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        stack<string> st;
        while(ss >> word){
            st.push(word);
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += " ";
        }
        return ans;
    }
};

// without using stringstream
class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        stack<string> st;
        string str = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(str != "")
                    st.push(str);
                str = "";
            } else {
                str += s[i];
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
            if(!st.empty())
                ans += " ";
        }
        return ans;
    }
};

// Two Pointers Approach:
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n-1;
        string ans;

        while(i >= 0){
            // skip spaces
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;
            // find the end of the word
            int j = i;
            // find the start of the word
            while(i >= 0 && s[i] != ' ') i--;
            // append the word to the answer
            if(!ans.empty()) ans += " ";
            ans += s.substr(i+1, j-i);
        }
        return ans;
    }
};

// Using reverse function
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int k = 0;

        reverse(s.begin(), s.end());

        while(i < n) {
            // Skip spaces
            while(i < n && s[i] == ' ') i++;
            if (i >= n) break;

            int j = i;
            // Find end of word
            while (j < n && s[j] != ' ') j++;

            // Reverse individual word
            reverse(s.begin() + i, s.begin() + j);

            // Add word to result in-place
            if (k > 0) {
                s[k++] = ' ';
            }

            for (int p = i; p < j; p++) {
                s[k++] = s[p];
            }

            i = j;
        }
        s.resize(k);
        return s;
    }
};
