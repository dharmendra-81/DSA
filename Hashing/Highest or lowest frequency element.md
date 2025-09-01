```cpp
#include<iostream>
#include<unordered_map>
using namespace std;
  
void Frequency(int arr[], int n)
{
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
    // Traverse through map to find the elements.
    for (auto it : map) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq) {
            minEle = element;
            minFreq = count;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}

int main(){
  cout<<endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    cout<<endl<<endl;
    return 0;
}
```
