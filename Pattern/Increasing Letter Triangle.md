---
source: Coding Ninjas
type: pattern
number: "14"
---
```
A 
A B 
A B C 
A B C D 
A B C D E 
```

**NOTE:** char uses single quote and strings use double quote.

```cpp
void nLetterTriangle(int n) {
  char ch;
  for (int i = 0; i < n; i++){
    ch='A';  
    for (int j = 0; j <= i; j++){
      cout<<ch<<" ";
      ch++;
    }
    cout << endl;
  }
}
```