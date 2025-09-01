```cpp
#include<iostream>
using namespace std;

int main(){ 
     int i,j,n; 
    cout<<"Enter order of matrix: "; 
    cin>>n; 
    int a[n][n],b[n][n],s[n][n]; 
    cout<<"enter elements in matrix A: "; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
        cin>>a[i][j]; 
    }} 
     cout<<"enter elements in matrix B: "; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
        cin>>b[i][j]; 
    }} 
 
    for(i=0;i<n;i++){ 
     for(j=0;j<n;j++){ 
         s[i][j]=a[i][j]+b[i][j]; 
    }} 
     cout<<"matrix A + B = \n"; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
        cout<<"\t"<<s[i][j]; 
    } 
    cout<<endl; 
    } 
    return 0; 
}
```
