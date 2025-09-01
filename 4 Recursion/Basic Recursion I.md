**Printing numbers from 0 to 3**
```cpp 
int count=0;
void f(){
  if (count==3){
    return;
  }
  cout<<count<<" ";
  count++;
  f();
}

```

**Print Name N times using Recursion**
```cpp title:
void f(int i,int n){
  if(i>n){
    return;
  }
  cout<<"Name ";
  f(i+1,n);
}
```

**Print 1 to N**
```cpp
void f(int i,int n){
  if(i>n){
    return;
  }
  cout<<i<<" ";
  f(i+1,n);
}
```

**Print N to 1**
```cpp
void f(int start,int n){
  if(start>n){
    return;
  }
  f(start+1,n);
  cout<<start<<" ";
}
```

