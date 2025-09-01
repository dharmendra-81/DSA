```cpp
#include<iostream>
using namespace std;

int main(){ 
     int i,j,n; 
    cout<<"Enter order of matrix: "; 
    cin>>n; 
    int a[n][n],sum=0; 
    cout<<"Enter elements in matrix A: "<<endl; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
        cout<<"a"<<i+1<<j+1<<"=";
        cin>>a[i][j]; 
    }} 
 
    for(i=0;i<n;i++){ 
     for(j=0;j<n;j++){ 
        if(i==j){ 
         sum=sum+a[i][j]; 
    }}} 
     cout<<"Sum of diagonals of the matrix = "<<sum; 
    return 0; 
}
```
