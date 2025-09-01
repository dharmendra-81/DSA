```
#include<iostream>
using namespace std;
 
int main(){ 
    int arr[10],i,sum=0; 
    cout<<"enter elements in array"; 
    for(i=0;i<10;i++){ 
    cin>>arr[i]; 
    } 
    for(i=0;i<10;i++){ 
        sum=sum+arr[i]; 
    } 
    cout<<"sum of elements = "<<sum; 
    return 0; 
}
```
