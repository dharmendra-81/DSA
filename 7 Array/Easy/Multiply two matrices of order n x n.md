```cpp
#include<iostream>
using namespace std;

int main(){ 
     int i,j,n,k; 
     cout<<"Enter order of matrix: "; 
     cin>>n; 
    int a[n][n],b[n][n],m[n][n]; 
    cout<<"Enter elements in matrix A: "<<endl; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
        cout<<"a"<<i+1<<j+1<<"=";
        cin>>a[i][j]; 
    }} 
     cout<<"Enter elements in matrix B: "<<endl; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
        cout<<"b"<<i+1<<j+1<<"=";
        cin>>b[i][j];
    }} 
 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
            m[i][j]=0; 
            for(k=0;k<n;k++){ 
        m[i][j]+=a[i][k]*b[k][j]; 
    }}} 
     cout<<"matrix A X B = "<<endl; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
        cout<<"\t"<<m[i][j]; 
    } 
    cout<<endl; 
    } 
    return 0; 
}
```
Enter order of matrix: 3
Enter elements in matrix A: 
a11=11
a12=12 
a13=13 
a21=14 
a22=15 
a23=16 
a31=17 
a32=18
a33=19 
Enter elements in matrix B:
b11=10 
b12=20 
b13=30
b21=40 
b22=50 
b23=60
b31=70
b32=80
b33=90
matrix A X B = 
1500 1860 2220 
1860 2310 2760
2220 2760 3300