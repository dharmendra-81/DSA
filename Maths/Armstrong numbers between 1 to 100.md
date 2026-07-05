---
source: BCS151
type: Basic
number: "15"
---

```cpp
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,n1,d,r,sum;
    cout<<"Armstrong numbers between 1 to 100 are:\n"; 
    for(n=1;n<=100;n++){
        n1=n;
        while(n!=0){
            d++;
            n=n/10;
        }
        n=n1;
        while(n!=0){
            r=n%10;
            sum=sum+pow(r,d);
            n=n/10;
        }
        if(sum==n1){
            cout<<n1<<" ";
        }
        
        n=n1;
        r=0;
        sum=0;  
        d=0; 
    }
    return 0;
}
```
 