---
source: BCS151
type: Basic
number: "16"
---

```cpp
#include<iostream> 
#include<cmath> 
using namespace std; 
 
int main(){ 
    int a,b,c; 
    cout<<"Enter the values of a,b and c from Quadratic equation"<<endl; 
    cin>>a>>b>>c; 
    float D;  //Discriminant 
    D=(b*b)-(4*a*c); 
    if(D>=0){ 
        cout<<"The roots are real : "; 
        int x1,x2; 
        x1=(-b+sqrt(D))/(2*a); 
        x2=(-b-sqrt(D))/(2*a); 
        cout<<x1<<" and "<<x2; 
    } 
    else{ 
        cout<<"Imaginary roots"; 
    } 
    return 0; 
}
```
