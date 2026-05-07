Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

**Symbol**       **Value**
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000

Given a roman numeral, convert it to an integer.

---
```cpp
int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int res=0;
        for(int i=0; i<s.size()-1; i++){
            if(roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res + roman[s.back()];
    }
    O(N)
```
