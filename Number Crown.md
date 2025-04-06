---
source: Coding Ninjas
type: pattern
number: "12"
---
```output
1                 1 
1 2             2 1 
1 2 3         3 2 1 
1 2 3 4     4 3 2 1 
1 2 3 4 5 5 4 3 2 1 
```


```cpp
void numberCrown(int n) {
  for (int i = 0; i < n; i++) {
      int x = 0;
      for (int j = 0; j < 2*n; j++) {
          if (j <= i) {
              ++x;
              cout << x << " ";
          }
          else if (i + j >= 2*n - 1) {
              cout << x << " ";
              x--;
          }
          else {
              cout << "  ";  
          }
      }
      cout << endl;
  }
}
```
