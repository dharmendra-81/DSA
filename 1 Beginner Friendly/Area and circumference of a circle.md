---
source: BCS151
type: Beginner
number: "03"
---

```c
#include<stdio.h>

int main(){
   float r, pi=3.14,a,c;
   printf("enter the radius of circle:");
    scanf("%f",&r);
    a=pi*r*r;
    c=2*pi*r;
    printf("Area of circle = %f",a);
    printf("\nCircumference of circle = %f",c);
    return 0;
}
```
