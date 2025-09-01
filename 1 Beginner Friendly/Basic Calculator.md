---
source: BCS151
type: Beginner
number: "12"
---

```c
#include<stdio.h>

int main(){
  int choice,a,b;
  printf("select your choice:\n");
  printf("1-add :\n");
  printf("2-sub :\n");
  printf("3-mul :\n");
  printf("4-div :\n");
  printf("5-mod :\n");
  printf("enter number a=");
  scanf("%d",&a);
   printf("enter number b=");
    scanf("%d",&b);
    printf("enter your choice:");
    scanf("%d",&choice);
 switch(choice){
  case 1:
  printf("add of a and b is %d",(a+b));
  break;
   case 2:
  printf("sub of a and b is %d",(a-b));
  break;
   case 3:
  printf("mul of a and b is %d",(a*b));
  break;
   case 4:
  printf("div of a and b is %d",(a/b));
  break;
   case 5:
  printf("mod of a and b is %d",(a%b));
  break;
   default:
  printf("wrong choice");
 }
  return 0;
}
```
