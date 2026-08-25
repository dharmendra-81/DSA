---
source: Coding Ninjas
type: pattern
number: "10"
aliases:
  - Rotated Triangle
---
```output
*
**
***
****
*****
****
***
**
*
```


```cpp
void nStarTriangle(int n)
{
  for (int i = 0; i < 2 * n - 1; i++)
  {
    for (int j = 0; (j <= i) && (i + j != 2 * n - 1); j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}
```