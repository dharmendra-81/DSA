---
source: geeksforgeeks
number: "3"
type: pattern
level: E
---

```output
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
```

```cpp
class Solution {
    public:
      void printTriangle(int n) {
        int x;
        for (int i = 0; i < n; i++)
        {
            x=1;
            for (int j=0;j<=i;j++)
            {
                cout<<x<<" ";
                x++;
            }
            cout<<endl;
        }

      }
  };
```
