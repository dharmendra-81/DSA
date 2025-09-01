---
source: BCS151
type: Beginner
number: "08"
---

```c
#include<stdio.h>

int main(){
    int a;
    printf("enter any number:");
    scanf("%d",&a);
    if(a%2==0){
        printf("even number");
    }
    else{
        printf("odd number");
    }
    return 0;
}
```
