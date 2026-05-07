---
source: BCS151
type: Basic
number: "13"
---

```cpp
#include<iostream>
#include<cmath>
using namespace std;
 
int main(){ 
    int n,d,i=0,sum=0; 
    cout<<"Enter any binary number: ";
    cin>>n;
    while(n>0){ 
    d=n%10; 
    sum=sum+d*pow(2,i); 
    n=n/10; 
    i++; 
    } 
    cout<<"decimal = "<<sum; 
    return 0; 
}
```
