---
source: BCS151
type: Beginner
number: "09"
---

```cpp
#include <iostream>
using namespace std;

int main()
{
    char l;
    cout << "Enter any letter: ";
    cin >> l;
    switch (l)
    {
    case 'a':
        cout << l << " is vowel";
        break;
    case 'e':
        cout << l << " is vowel";
        break;
    case 'i':
        cout << l << " is vowel";
        break;
    case 'o':
        cout << l << " is vowel";
        break;
    case 'u':
        cout << l << " is vowel";
        break;
    default:
        cout << l << " is consonant";
    }
    return 0;
}
```
 