---
source: Coding Ninjas
type: pattern
number: "16"
---
```output
A 
B B 
C C C 
D D D D 
E E E E E 
```

```cpp
void alphaRamp(int n) {
  char ch='A';
  for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        cout<<ch<<" ";
      }
      ch++;
      cout << endl;
  }
}
```
