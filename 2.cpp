#include <iostream>
using namespace std;

int binarySearch(int a[], int size, int key)
{
    int low, mid, high;
    low = 0, high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < key)
            low = mid + 1;  
        else if (a[mid] == key)
            return mid;
        else
            high = mid - 1;
        }
    return -1;
}

int main()
{
    int key, n;
    cout << "How many elements" << endl;
    cin >> n;
    if(n<=0)
    return -1;
    int ar[n];
    cout << "Enter elements in sorted manner" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << "Enter the element you want to find: ";
    cin >> key;
    int index = binarySearch(ar, n, key);
    if(index>=0)
    cout << "Element found at " << index + 1 << "th position";
    else
    cout<<key<<" not found";
    return 0;
}
