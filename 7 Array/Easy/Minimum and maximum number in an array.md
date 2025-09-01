```
#include <iostream>
using namespace std;

int main()
{
    int arr[6], min, i, max;
    cout << "Enter elements in array" << endl;
    for (i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    min = arr[0];
    max = arr[0];
    for (i = 0; i < 6; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min;
    return 0;
}
```
