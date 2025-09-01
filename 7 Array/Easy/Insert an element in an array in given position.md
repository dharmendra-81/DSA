```cpp
#include<iostream> 
using namespace std; 
 
int main(){ 
    int a[10],i,pos,val; 
    for(i=0;i<9;i++){ 
        cout<<"Enter the number "; 
        cin>>a[i]; 
    } 
 
    cout<<"Original Array: "; 
    for(i=0;i<9;i++){ 
        cout<<a[i]<<" "; 
    } 
 
    cout<<"\nEnter the position: "; 
    cin>>pos; 
    
    cout<<"Enter the value: "; 
    cin>>val; 
     
    for(i=8;i>=pos-1;i--){ 
        a[i+1]=a[i]; 
    } 
    a[pos-1]=val; 
 
    cout<<"Modified Array: "; 
    for(i=0;i<10;i++){ 
        cout<<a[i]<<" "; 
    } 
    return 0; 
}
```
Enter the number 12 
Enter the number 15 
Enter the number 25 
Enter the number 14 
Enter the number 31 
Enter the number 26 
Enter the number 27
Enter the number 19
Enter the number 31 
Original Array: 12 15 25 14 31 26 27 19 31
Enter the position: 4 
Enter the value: 35 
Modified Array: 12 15 25 35 14 31 26 27 19 31
