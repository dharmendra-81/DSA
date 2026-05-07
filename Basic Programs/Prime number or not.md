---
source: BCS151
type: Basic
number: "05"
---

```cpp
#include <iostream>
using namespace std;

int main()
{
    int no, i, count = 0;
    cout << "Enter any number: ";
    cin >> no;
    for (i = 1; i <= no; i++)
    {
        if (no % i == 0)
            count++;
    }
    if (count == 2)
        cout << no << " is a prime number";
    else
        cout << no << " is not a prime number";
    return 0;
}
```
 