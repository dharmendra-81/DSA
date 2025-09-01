---
source: BCS151
type: Beginner
number: "07"
---

```c
#include<stdio.h>

int main(){
   int a,b,c;
   printf("enter the first number:");
    scanf("%d",&a);
    printf("enter the second number:");
    scanf("%d",&b);
    printf("enter the third number:");
    scanf("%d",&c);
    if(a>b && a>c){
        printf("%d is greatest number",a);
    }
    else if(b>a && b>c){
        printf("%d is greateat number",b);
    }
    else{
        printf("%d is greatest number",c);
    }
    return 0;
}
```
