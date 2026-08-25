---
source: BCS151
type: Basic
number: "01"
---

```cpp
#include <iostream>
using namespace std;

int main()
{
    int date;
    cout << "Enter the date: ";
    cin >> date;
    if (date <= 31)
    {
        switch (date % 7)
        {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            ;
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 0:
            cout << "Sunday";
            break;
        default:
            cout << "ERROR 404";
        }
    }
    else
        cout << "A month does not have more than 31 days";
    return 0;
}
```
