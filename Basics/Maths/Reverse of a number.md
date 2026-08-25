---
source: BCS151
type: Basic
number: "07"
---

```cpp
#include<iostream>
using namespace std;

int main(){
    int n,d,sum=0;
    cout<<"Enter any number: ";
    cin>>n;
    while(n>0){ 
        d=n%10; 
        sum=d+sum*10; 
        n=n/10; 
    } 
    cout<<"Reverse of the number = "<<sum;
    return 0;
}
```
