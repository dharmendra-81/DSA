**Sum of first N Natural Numbers**
```cpp
//Parameterized way
void f(int sum, int i){
  if (i<1){
    cout<<sum;
    return;
  }
  f(sum+i, i-1);
}
//Functional way
int f(int n){
  if (n==0){
    return 0;
  }
  return n+f(n-1);
}
```

**Factorial of a Number**
```cpp
int fact(int n){
  if (n<=0){
    return 1;
  }
  return n*fact(n-1);
}
```

**Reverse a given Array**
```cpp
void reverseArray(int arr[], int start, int end) {
  if (start<end){
    swap(arr[start],arr[end]);
    reverseArray(arr,start+1,end-1);
  }
}
```
