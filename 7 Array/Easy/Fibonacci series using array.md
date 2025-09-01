```cpp
#include <iostream>
using namespace std;

int main()
{
    int F[10], i;
    cout << "Fibonacci series: ";
    F[0] = 0;
    F[1] = 1;
    for (i = 2; i < 10; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    for (i = 1; i < 10; i++)
    {
        cout << F[i] << "\t";
    }
    return 0;
}
```
 