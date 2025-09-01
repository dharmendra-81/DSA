---
source: Coding Ninjas
type: pattern
number: "22"
---
```
4444444
4333334
4322234
4321234
4322234
4333334
4444444
```


![[Drawing 2025-04-11 09.13.27.excalidraw]]
```cpp
void getNumberPattern(int n) {
  for (int i = 0; i < 2*n-1; i++) {
      for (int j = 0; j < 2*n-1; j++) {
        int top = i;
        int left =j ;
        int bottom = (2*n-2)-top;
        int right = (2*n-2)-left;
        int intermediate_Matrix = min( min(top,left), min(bottom,right) );
        cout << n - intermediate_Matrix;
      }
      cout << endl;
  }
}
```