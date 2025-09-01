---
source: BCS151
type: Basic
number: "08"
---

```cpp
#include<iostream>
using namespace std;
int p(int no);  //function declaration
int main(){
  int no;
cout<<"Enter any number\n";
cin>>no;
cout<<no<<" is ";
if(no==p(no))    //function call
cout<<"palindrome";
else
cout<<"not palindrome";
    return 0;
}
int p(int no)    //function definition
{
int sum=0,d;
while(no!=0)
{
d=no%10;
no=no/10;
sum=d+sum*10;
}
return sum;
}
```
