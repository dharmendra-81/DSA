```cpp
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr
    //storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left 
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    //  if elements on the right half are still left 
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr 
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
       cout << arr[i] << " ";
    }
}
  
int main(){
    cout<<endl;
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    cout<<"Array before sorting: ";
    printArray(arr);
    cout<<endl;
    mergeSort(arr, 0, arr.size() - 1);
    cout<<"Array after sorting: ";
    printArray(arr);
    cout<<endl<<endl;
    return 0;
}
```
