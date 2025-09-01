---
source: BCS151
type: Beginner
number: "02"
---

```c
#include<stdio.h>
#include<math.h>
int main(){
    float p,r,t,si,ci;
    printf("enter the principal amount:");
    scanf("%f",&p);
    printf("enter the rate of interest:");
    scanf("%f",&r);
    printf("enter the time in year:");
    scanf("%f",&t);
    si=(p*r*t)/100;
    ci=p*pow(1+r/100,t)-p;
    printf("simple interset is %f",si);
    printf("\ncompound interset is %f",ci);
    return 0;
}
```
`enter the principal amount:100000 
`enter the rate of interest:7` 
`enter the time in year:1` 
`simple interset is 7000.000000` 
`compound interset is 7000.005371`