You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

---
#### Naive Approach (Brute force)
$$
O(N^2)
$$
```cpp
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); 
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }
        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;
        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}
```

#### Better Approach (Using Hashing)
$$
O(2N)
$$
```cpp
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); 
    int hash[n + 1] = {0}; 
    //update the hash array:
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }
    //Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;
        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}
```

### Optimal Approach 1 (Using Maths)
$$
O(N)
$$
```cpp
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); 
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    //S-Sn = X-Y:
    long long val1 = S - SN; //X-Y
    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N; //X^2-Y^2
    val2 = val2 / val1; //X+Y
    //2X = (X+Y) + (X-Y) -> X = ((X+Y) + (X-Y))/2 -> (val2 + val1)/2
    long long x = (val1 + val2) / 2; //Repeating number
    long long y = x - val1; //Missing number
    return {(int)x, (int)y};
}
```

### Optimal Approach 2 (Using XOR)
$$
O(N)
$$
```cpp
vector<int> findMissingAndRepeatingNumber(vector<int> a) {
    int n = a.size();
    int xr = 0;
    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }
    //Step 2: Find the differentiating bit number:
    int number = 0;
    while (true) {
        if ((xr & (1 << number)) != 0) break;
        number++;
    }
    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & (1 << number)) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }
    //group the numbers from 1 to n:
    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & (1 << number)) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }
    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }
    // The function returns {repeating, missing}
    if (cnt == 2) return {zero, one};
    return {one, zero};
}
```
