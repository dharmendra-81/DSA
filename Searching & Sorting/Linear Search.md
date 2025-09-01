```cpp
#include<iostream>
using namespace std;

int main(){ 
    int i,ar[10],n,count=0; 
    cout<<"Enter elements in array"<<endl; 
    for(i=0;i<10;i++){ 
        cin>>ar[i]; 
    } 
    cout<<"Enter the element you want to find: "; 
    cin>>n; 
   for(i=0;i<10;i++){ 
    if(n==ar[i]){ 
        count++; 
        break; 
    } 
   } 
   if(count==1){ 
    cout<<"Element found at "<<i+1<<"th position"; 
   } 
   else{ 
    cout<<"Element not found"; 
   } 
    return 0; 
}
```
Enter elements in array 
10
20
30
40
15
12
11
18
70
17
Enter the element you want to find: 70 
Element found at 9th position