**Given two sorted arrays, `**arr1,**` and `**arr2**` of size `**n**` and `**m**.` Find the union of two sorted arrays.
The union of two arrays can be defined as the common and distinct elements in the two arrays.
```cpp
vector<int> unionVectors(vector<int> A, vector<int> B){
    vector<int> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()){
        if (A[i] <= B[j]){
            if (result.size() == 0 || result.back() != A[i]){
                result.push_back(A[i]);
            }
            i++;
        }
        else {
            if (result.size() == 0 || result.back() != B[j]) {
                result.push_back(B[j]);
            }
            j++;
        }
    }
    while (i < A.size()){
        if (result.back() != A[i]){
            result.push_back(A[i]);
        }
        i++;
    }
    while (j < B.size()){
        if (result.back() != B[j]){
            result.push_back(B[j]);
        }
        j++;
    }
    return result;
}
```
