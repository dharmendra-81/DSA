---
source: Coding Ninjas
type: pattern
number: "11"
---
```output
1
01
101
0101
10101
```


```cpp
void nBinaryTriangle(int n) {
  int x;
  for (int i = 0; i < n; i++){
    if (i%2==0)
    x=1;
    else
    x=0;
    for (int j = 0; j <= i; j++){
      cout<<x<<" ";
      if (x==0)
      x=1;
      else
      x=0;
    }
    cout << endl;
  }
}
```