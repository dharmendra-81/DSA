---
source: BCS151
type: Basic
number: "10"
---

```cpp
#include<iostream>
using namespace std;

int main(){
    int f=1,n;
    int a=0,b=1;
    int sumf=0; //to print sum of series
    cout<<"Enter nth value : ";
    cin>>n;
    cout<<"Fibonacci Sequence : ";
    while(f<=n){
        cout<<f<<" ";
        sumf=sumf+f; //for sum of series
        f=a+b;
        a=b;
        b=f;
        }
    cout<<"\nSum of Fibonacci Sequence : "<<sumf;
    return 0;
}
```
