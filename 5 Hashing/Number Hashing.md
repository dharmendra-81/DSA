```cpp
int n=5;
  int arr[n] = {1,2,1,3,2};
  // Precompute
  int hash[13]={0};
  for (int i = 0; i < n; i++){
    hash[ arr[i] ] +=1;
  }
  int q; 
  cout<<"Enter the number of queries: ";
  cin>>q;
  while(q--){
    int number;
    cout<<"Enter the number to be searched: ";
    cin>>number;
    // fetch
    cout<<hash[number]<<endl;
  }
```

**OUTPUT**
Enter the number of queries: 4
Enter the number to be searched: 1
2
Enter the number to be searched: 2
2
Enter the number to be searched: 3
1
Enter the number to be searched: 10
0

**Problem ⚠️**
Max. size for int array is $10^6$  inside main( ).