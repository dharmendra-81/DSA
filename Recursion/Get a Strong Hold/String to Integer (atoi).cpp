// https://leetcode.com/problems/string-to-integer-atoi/description/

// Iterative Approach -> Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long res=0;
        while(i < s.size() && s[i] == ' ')
            i++;
        
        //ignore 0 if only spaces are found
        if(i == s.size())
            return 0;
        
        if(s[i] =='-'){
            sign =-1;
            i++;
        }
        else if(s[i] == '+')
            i++;

        //convert char to int while valid digits
        while(i < s.size() && isdigit(s[i])){
            res = res*10 + (s[i] - '0');

            //if underflow and overflow occurs
            if(sign*res > INT_MAX)
                return INT_MAX;
            if(sign*res < INT_MIN)
                return INT_MIN;

            i++;
        }
        return (int)(sign*res);
    }
};


// Recursive Approach -> Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
public:
    int f(string &s, int i, long long num, int sign){
        if(i>=s.size() || !isdigit(s[i])) 
            return (int) sign*num;
        num = num*10 + (s[i]-'0');
        if(sign*num > INT_MAX) return INT_MAX;
        if(sign*num < INT_MIN) return INT_MIN;
        return f(s, i+1, num, sign);
    }

    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            sign = (s[i]=='-') ? -1 : 1;
            i++;
        }
        return f(s, i, 0, sign);
    }
};