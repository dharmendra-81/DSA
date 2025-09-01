---
source: BCS151
type: Beginner
number: "01"
---

```c
#include<stdio.h>

int main(){
     int p,c,m,pe,e,sum;
   float per;
   printf("enter the marks for physics: ");
   scanf("%d",&p);
    printf("enter the marks for chemistry: ");
   scanf("%d",&c);
    printf("enter the marks for mathematics: ");
   scanf("%d",&m);
    printf("enter the marks for physical education: ");
   scanf("%d",&pe);
    printf("enter the marks for english: ");
   scanf("%d",&e);
   sum=p+c+m+pe+e;
   per=sum/5.0;
   printf("Sum = %d",sum);
   printf("\nPercentage = %f%\n",per);
   if(per>=90 && per<100){
    printf("grade A");
   }
   else if(per>=80 && per<90){
    printf("grade B");
   }
   else if(per>=60 && per<80){
    printf("grade C");
   }
   else if(per<60){
    printf("grade D");
   }
    return 0;
}
```
