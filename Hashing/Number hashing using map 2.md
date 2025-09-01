```cpp
cout<<"Enter the size of the array: ";
  int n;
  cin>>n;
  int arr[n]={1,2,3,1,3,2,12};
  // Precompute
  unordered_map<int,int> mpp;
  for(int i=0;i<n;i++){
    mpp[arr[i]]++;
  }
  for(auto it:mpp){
    cout<<it.first<<"    ->    "<<it.second<<endl;
  }
```

**OUTPUT**
Enter the size of the array: 10
0    ->    3
12    ->    1
3    ->    2
2    ->    2
1    ->    2