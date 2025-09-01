```cpp
#include<iostream> 
using namespace std; 
 
int main(){ 
    int a[10],i,del,flag=0; 
    for(i=0;i<10;i++){ 
        cout<<"Enter the number "; 
        cin>>a[i]; 
    } 
 
    cout<<"Original Array: "; 
    for(i=0;i<10;i++){ 
        cout<<a[i]<<" "; 
    } 
    
    cout<<"\nElement to be removed: "; 
    cin>>del; 
     
    for(i=0;i<10;i++){ 
        if(a[i]==del){ 
            flag=1; 
            break; 
        } 
    } 
    if(flag==0){ 
        cout<<"Element not found"; 
    } 
    else{  
            while(i<9){                   //for(;i<9;i++) 
            a[i]=a[i+1]; 
            i++; 
        } 
    } 
 
    cout<<"Modified Array: "; 
    for(i=0;i<9;i++){ 
        cout<<a[i]<<" "; 
    } 
    return 0; 
}
```
Enter the number 12 
Enter the number 15 
Enter the number 86 
Enter the number 25 
Enter the number 34
Enter the number 42 
Enter the number 21
Enter the number 27 
Enter the number 19
Enter the number 31
Original Array: 12 15 86 25 34 42 21 27 19 31 
Element to be removed: 25 
Modified Array: 12 15 86 34 42 21 27 19 31
