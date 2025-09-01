---
source: BCS151
type: Beginner
number: "05"
---

```c
#include<stdio.h>

int main(){
   int a,b,temp;
   a=3,b=2;
   printf("before swap a=%d b=%d",a,b);
   temp=a;
   a=b;
   b=temp;
   printf("\nafter swap a=%d b=%d",a,b);
    return 0;
}
```
