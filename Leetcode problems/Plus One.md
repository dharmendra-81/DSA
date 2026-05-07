> 66

**You are given a large integer represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.
Increment the large integer by one and return _the resulting array of digits_.**
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; 
            }
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

```


> [!NOTE] Explanation
> Traverse the digits array from the last element backward
>  If the current digit is less than 9, increment it
>  If the current digit is 9, set it to 0
>  If all digits were 9, we need to insert a 1 at the beginning
