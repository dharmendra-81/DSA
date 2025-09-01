---
source: BCS151
type: Beginner
number: "13"
---

```cpp
#include<iostream> 
using namespace std; 
 
int main(){ 
    int i=1,num; 
    cout<<"Enter the number whose multiplication table you want to see"<<endl; 
    cin>>num; 
    cout<<"Multiplication Table of "<<num<<":"<<endl; 
    while(i<=10){ 
        cout<<num<<" X "<<i<<" = "<<num*i<<endl; 
        i++; 
    } 
    return 0; 
}
```
Enter the number whose multiplication table you want to see 
19 
Multiplication Table of 19: 
19 X 1 = 19 
19 X 2 = 38 
19 X 3 = 57 
19 X 4 = 76 
19 X 5 = 95 
19 X 6 = 114 
19 X 7 = 133 
19 X 8 = 152 
19 X 9 = 171 
19 X 10 = 190
