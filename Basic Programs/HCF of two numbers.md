---
source: BCS151
type: Basic
number: "11"
---

```cpp
#include<iostream>
using namespace std;

int main(){
    int a,b,r;
    cout<<"Enter any two integers:"<<endl;
    cin>>a>>b;
    while(a!=0){
        r=b%a;
        b=a;
        a=r;
    }
    cout<<"HCF of these numbers are "<<b;
    return 0;
}
```
