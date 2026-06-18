// print all subsequences of an array whose sum is equal to k
void printSubsequences(int i, int sum, int k, vector<int> &temp, vector<int> &arr){
    if (i == arr.size()){
        if (sum == k){
            for (int x : temp) cout << x << " ";
            cout << endl;
        }
        return;
    }
    temp.push_back(arr[i]);
    printSubsequences(i + 1, sum + arr[i], k, temp, arr);
    temp.pop_back();
    printSubsequences(i + 1, sum, k, temp, arr);
}

// print any one subsequence of an array whose sum is equal to k
bool solve(int i, int sum, int k, vector<int> &temp, vector<int> &arr){
    if (i == arr.size()){
        if (sum == k) {
            for (int x : temp) cout << x << " ";
            cout << endl;
            return true;
        }
        else return false;
    }
    temp.push_back(arr[i]);
    if (solve(i + 1, sum + arr[i], k, temp, arr)) return true;
    temp.pop_back();
    if (solve(i + 1, sum, k, temp, arr)) return true;
    return false;
}

// count the number of subsequences of an array whose sum is equal to k
int countSubsequences(int i, int sum, int k, vector<int> &arr){
    if (i == arr.size()){
        if (sum == k) return 1;
        else return 0;
    }
    int count = 0;
    count += countSubsequences(i + 1, sum + arr[i], k, arr);
    count += countSubsequences(i + 1, sum, k, arr);
    return count;
}