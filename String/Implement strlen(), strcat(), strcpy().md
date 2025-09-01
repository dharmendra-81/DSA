```
#include<stdio.h> 
#include<string.h> 
int main(){ 
    char st[20]={'H','e','l','l','o',' ','W','o','r','l','d','\0'}; 
    printf("length of string '%s' = %d\n",st,strlen(st)); 
    char w1[10]="Hello"; 
    char w2[10]="World"; 
    strcat(w1,w2); 
    printf("First word is: %s",w1); 
    char source[]="India"; 
    char target[10]; 
    strcpy(target,source); 
    printf("\nString1 is %s",source); 
    printf("\nString2 is %s",target); 
    return 0; 
}
```
#Strings