---
source: Coding Ninjas
type: pattern
number: "19"
---
```
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
```

```cpp
void symmetry(int n) {
  for (int i = 0; i < 2*n; i++) {
      for (int j = 0; j < 2*n; j++) {
          if (i+j >= n && j-i <= n-1 && i < n ) {
            cout << "  ";
          }
          else if ( i-j <= n-1 && i+j <= 3*n-2 && i >= n ) {
            cout << "  ";

          }
          else {
              cout << "* ";  
          }
      }
      cout << endl;
  }
}
```

