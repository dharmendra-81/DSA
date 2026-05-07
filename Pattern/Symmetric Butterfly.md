---
source: Coding Ninjas
type: pattern
number: "20"
---
```
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 
```


```cpp
void symmetry(int n) {
  for (int i = 0; i < 2*n-1; i++) {
      for (int j = 0; j < 2*n; j++) {
          if ( j-i >= 1 && i+j <= 2*n-2 ) {
            cout << "  ";
          }
          else if ( i+j >= 2*n-1 && j<=i ) {
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
