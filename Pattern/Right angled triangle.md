---
source: geeksforgeeks
type: pattern
number: "2"
level: E
---

```output
*
**
***
****
*****
******
```

```cpp
void rightAngledTriangle(int count){
    for (int i = 0; i < count; i++)
    {
        for (int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

```
