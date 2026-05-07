Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

---
```cpp
int func(int mid, int n, int m){
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = ans * mid;
        if (ans > m) return 2;  // mid^n > m
    }
    if (ans == m) return 1;     // mid^n == m
    return 0;                   // mid^n < m
}

int nthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2; 
        int midN = func(mid, n, m);
        if (midN == 1) return mid;
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

```
