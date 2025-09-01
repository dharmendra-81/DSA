**Is String Palindrome**
```cpp
bool Palindrome(int i,string & s) {
  if (i>=s.length()/2) return true;
  if ( s[i]!=s[s.length()-i-1] ) return false;
  return Palindrome(i+1,s);
}
```

**Fibonacci Series up to Nth term**
```cpp
int fibonacci(int N){
  if(N <= 1){
      return N;
  }
  int last = fibonacci(N-1);
  int slast = fibonacci(N-2);
  return last + slast;
}
```
