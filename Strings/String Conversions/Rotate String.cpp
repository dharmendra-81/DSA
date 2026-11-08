// Brute force : O(n^2)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        for(int i = 0; i < s.length(); i++){
            string rotated = s.substr(i) + s.substr(0,i);
            if(rotated == goal) return true;
        }
        return false;
    }
};

// Optimized approach : O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};