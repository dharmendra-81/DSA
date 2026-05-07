You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

**Note:** _The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n._

---
```cpp
int floorSqrt(int n) {
    int low = 1, high = n;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (mid * mid <= n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}
```
