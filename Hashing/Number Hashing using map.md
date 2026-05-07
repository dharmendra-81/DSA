```cpp
cout<<"Enter the size of the array: ";
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  // Precompute
  unordered_map<int,int> mpp;
  for(int i=0;i<n;i++){
    mpp[arr[i]]++;
  }
  int q; 
  cout<<"Enter the number of queries: ";
  cin>>q;
  while(q--){
    int number;
    cout<<"Enter the number to be searched: ";
    cin>>number;
    // fetch
    cout<<mpp[number]<<endl;
  }
```


**OUTPUT**
Enter the size of the array: 7
1
2
3
1
3
2
12
Enter the number of queries: 4
Enter the number to be searched: 1
2
Enter the number to be searched: 3
2
Enter the number to be searched: 10
0
Enter the number to be searched: 12
1