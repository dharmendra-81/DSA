> 13

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
           if (i < s.size() - 1 && value(s[i]) < value(s[i + 1])) {
                ans -= value(s[i]);
            } else {
                ans += value(s[i]);
            }
        }
        return ans;
    }
private:
    int value(char r) {
        if (r == 'I') return 1;
        if (r == 'V') return 5;
        if (r == 'X') return 10;
        if (r == 'L') return 50;
        if (r == 'C') return 100;
        if (r == 'D') return 500;
        if (r == 'M') return 1000;
        return 0;
    }
};

int main() {
    Solution sol;
    string s;
    cin>>s;
    int result = sol.romanToInt(s);
    cout << result << endl;
    return 0;
}
```
