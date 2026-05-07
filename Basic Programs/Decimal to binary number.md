---
source: BCS151
type: Basic
number: "14"
---

```cpp
#include<iostream>
using namespace std;
 
int main(){ 
    int n,r,i=1,sum=0; 
    cout<<"Enter any number: ";
    cin>>n;
   while(n>0){ 
   r=n%2; 
   n=n/2; 
   sum=sum+i*r; 
   i=i*10; 
   } 
   cout<<"binary = "<<sum; 
    return 0; 
}
```
