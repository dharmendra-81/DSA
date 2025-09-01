---
source: BCS151
type: Basic
number: "03"
---

```cpp
#include<iostream>
using namespace std;

void swapptr(int *a,int *b){ 
    int temp; 
    temp=*a; 
    *a=*b; 
    *b=temp; 
}

void swapRefVar(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

int main(){ 
    int x=2,y=3; 
    cout<<"Before swap x = "<<x<<" and y = "<<y<<endl;
    swapptr(&x,&y); 
    cout<<"After swap x = "<<x<<" and y = "<<y<<endl;
    swapRefVar(x,y);
    cout<<"Again swaping x = "<<x<<" and y = "<<y;
    return 0; 
} 
```
