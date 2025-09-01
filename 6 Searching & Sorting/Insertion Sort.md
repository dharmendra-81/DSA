- Worst Case O( $n^2$)
- Best Case O( n)
- Stable 
- Adaptive
- Intermediate result is not useful

```cpp
void insertionSort(int *a, int n){
    int key;
    for (int i=1; i<n; i++){
        key=a[i];
        for(int j=i-1; j>=0; j--){
            if( key< a[j] ){
                swap( a[j+1], a[j] );
            }
        }
    }
}
```

