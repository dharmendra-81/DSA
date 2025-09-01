- Max swaps = n-1
- Not stable
- Not Adaptive
- Sorting in Min number of swaps
- O( $n^2$ )

```cpp
void selectionSort(int *a, int n){
    int indexOfMin;
    for (int i=0; i<n-1; i++){
        indexOfMin=i;
        for(int j=i+1; j<n; j++){
            if( a[j]<a[indexOfMin] ){
                indexOfMin=j;
            }
        }
        if(a[indexOfMin]<a[i]){
            swap( a[indexOfMin], a[i]);
        }
    }
}
```
