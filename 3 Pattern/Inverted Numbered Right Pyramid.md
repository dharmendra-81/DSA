---
source: geeksforgeeks
type: pattern
number: "6"
---

```output
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 
```

```cpp
class Solution {
    public:
      void printTriangle(int n) {
        int x;
        for (int i = 0; i < n; i++)
        {
            x=1;
            for (int j=n;j>i;j--)
            {
                cout<<x<<" ";
                x++;
            }
            cout<<endl;
        }

      }
  };
```
