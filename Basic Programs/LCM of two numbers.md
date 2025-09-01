---
source: BCS151
type: Basic
number: "12"
---

```cpp
#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter any two integers:"<<endl;
    cin>>a>>b;
    int maxNum=max(a,b);
    while(true){
        if(maxNum%a==0 && maxNum%b==0)
          break;
        maxNum++;  
    }
    cout<<"LCM of "<<a<<" and "<<b<<" is "<<maxNum;
    return 0;
}
```
