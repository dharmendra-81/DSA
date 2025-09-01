---
source: BCS151
type: Basic
number: "02"
---

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x, n500, n100, n50, n20, n10, n5, n2, n1;
    cout << "Enter the amount: ";
    cin >> x;
    n500 = x / 500;
    cout << "No. of 500 rs notes = " << n500 << endl;
    x = x - (500 * n500);
    n100 = x / 100;
    cout << "No. of 100 rs notes = " << n100 << endl;
    x = x - (100 * n100);
    n50 = x / 50;
    cout << "No. of 50 rs notes = " << n50 << endl;
    x = x - (50 * n50);
    n20 = x / 20;
    cout << "No. of 20 rs notes = " << n20 << endl;
    x = x - (20 * n20);
    n10 = x / 10;
    cout << "No. of 10 rs notes = " << n10 << endl;
    x = x - (10 * n10);
    n5 = x / 5;
    cout << "No. of 5 rs notes = " << n5 << endl;
    x = x - (5 * n5);
    n2 = x / 2;
    cout << "No. of 2 rs notes = " << n2 << endl;
    x = x - (2 * n2);
    n1 = x / 1;
    cout << "No. of 1 rs notes = " << n1;
    return 0;
}
```
