---
source: BCS151
type: Beginner
number: "11"
---

```c
#include<stdio.h>
int main(){
  int n,i,seven=0,sodd=0;
 printf("enter any number:");
    scanf("%d",&n);
for(i=1;i<=n;i++){
  if(i%2==0){
    seven=seven+i;
  }
  else{
    sodd=sodd+i;
  }}
  printf("sum of all even numbers = %d",seven);
  printf("\nsum of all odd numbers = %d",sodd);
  return 0;
}
```
