---
source: BCS151
type: Beginner
number: "04"
---

```c
#include<stdio.h>

int main(){
    float c,f,k;
    printf("enter the temperature in celsius:");
    scanf("%f",&c);
    f=((9*c)/5)+32;
    k=c+273.15;
    printf("Temperature in fahrenheit = %f",f);
    printf("Temperature in kelvin = %f",k);
    return 0;
}
```
