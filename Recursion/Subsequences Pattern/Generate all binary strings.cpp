// Given an integer n, return all binary strings of length n that do not contain consecutive 1s. 
// Return the result in lexicographically increasing order. 

// Time : O(2^n) and Space : O(2^n) for storing the answer
class Solution {
    public:
    void generate(int n, const string &s, vector<string> &ans) {
        if(s.size() == n) {
            ans.push_back(s);
            return;
        }

        generate(n, s + "0", ans); // always add 0

        if(s.empty() || s.back() == '0') { // add 1 only if the last character is not 1
            generate(n, s + "1", ans);
        }
    }
};

int main() {
    int n = 3;
    vector<string> ans;
    string s = "";
    Solution sol;
    sol.generate(n, s, ans);
    
    for(const auto &str : ans) {
        cout << str << endl;
    }
    
    return 0;
}

