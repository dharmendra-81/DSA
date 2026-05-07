Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). A word is defined as a sequence of non-space characters. The words in s are separated by at least one space.  
  
Return a string with the words in reverse order, concatenated by a single space.

---
# Brute Force
```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(); 
        vector<string> words;
        int start, end;
        
        int i = 0;
        while(i < n) {
            
            // Finding the first character of a word (if any)
            while(i < n && s[i] == ' ') 
              i++;
            
            // If no word is found, break 
            if(i >= n) 
              break;
            
            start = i; // Storing the index of first character of word
            
            // Finding the last character of the word
            while(i < n && s[i] != ' ') 
              i++;
            
            end = i-1; // Storing the index of last character of word
            
            // Add the found word to the list of words
            string wordFound = s.substr(start, end-start+1);
            words.push_back(wordFound);
        }
        
        string ans = "";
        
        // Adding all the words to result in the reverse order 
        for(int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            
            // Adding spaces in between words
            if(i != 0) ans.push_back(' ');
        }
        return ans; 
    } 
};
O(N)
O(N)
```

# Optimal
```cpp
class Solution {
private:
    void reverseString(string &s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

public:
    string reverseWords(string s) {
        int n = s.length();

        // Reverse the entire string
        reverseString(s, 0, n - 1);

        int i = 0, j = 0;
        int start = 0, end = 0;

        while (j < n) {
            // Skip spaces
            while (j < n && s[j] == ' ') 
              j++;
            if (j == n) 
              break;

            start = i;

            // Copy the word characters forward
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            end = i - 1;

            // Reverse the current word using start and end
            reverseString(s, start, end);

            // Add a space after the word if it's not the last word
            if (j < n) {
                s[i++] = ' ';
            }
        }

        // Remove trailing space if present
        if (i > 0 && s[i - 1] == ' ') 
          i--;
        return s.substr(0, i);
    }
};
O(N)
```
