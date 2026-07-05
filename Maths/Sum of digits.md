---
source: BCS151
type: Basic
number: "06"
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
    sum=sum+d;
    n=n/10;
    }
    cout<<"sum of digits of a number = "<<sum;
    return 0;
}
```
