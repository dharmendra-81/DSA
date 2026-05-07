> 70

**You are climbing a staircase. It takes `n` steps to reach the top.
Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?**

```cpp
class Solution { 
public:
int climbStairs(int n) { 
if (n <= 1) {
return 1;
} 
int a = 1;
int b = 1;
for (int i = 2; i <= n; ++i) {
int curr = a + b;
b = a;
a = curr;
}
return a;
}
};
```
