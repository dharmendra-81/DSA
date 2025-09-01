- O($n^2$ )
- Stable
- By default not adaptive

```cpp
void bubbleSort(int *arr, int n){
    for (int i=0; i<n-1; i++){
        for(int j=i; j<n-1-i; j++){
            if( arr[j]>arr[j+1] ){
                swap( arr[j], arr[j+1] );
            }
        }
    }
}
```

**Bubble Sort Adaptive**
O(n) for already sorted
```cpp
void bubbleSortAdaptive(int *arr, int n){
    bool isSorted=false;
    for (int i=0; i<n-1; i++){
        isSorted=true;
        for(int j=i; j<n-1-i; j++){
            if( arr[j]>arr[j+1] ){
                swap( arr[j], arr[j+1] );
                isSorted=false;
            }
        }
        if(isSorted){
            return;
        }
    }
}
```

