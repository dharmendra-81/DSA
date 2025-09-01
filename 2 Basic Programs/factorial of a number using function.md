---
source: BCS151
type: Basic
number: "09"
---

```cpp
#include<iostream>
using namespace std;

int fact(int no)
{
int f=1,d,i;
for(i=1;i<=no;i++)
{
  f=f*i;
}
return f;
}

int main()
{
int no,c;
cout<<"Enter any number\n";
cin>>no;
c=fact(no);
cout<<no<<"! = "<<c;
return 0;
}
```


