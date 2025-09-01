```cpp
#include<iostream>
using namespace std;

void reverse(int *ar,int n);
int main(){
    int ar[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        cout<<"array["<<i<<"] = "<<ar[i]<<endl;
    }
    reverse(ar,7);
    cout<<"After reversing the array:"<<endl;
    for(int i=0;i<7;i++){
        cout<<"array["<<i<<"] = "<<ar[i]<<endl;
    }
    return 0;
}
void reverse(int *ar,int n){
    int temp;
    for(int i=0;i<(n/2);i++){
        temp=ar[i];
        ar[i]=ar[n-i-1];
        ar[n-i-1]=temp;
    }
}
```
