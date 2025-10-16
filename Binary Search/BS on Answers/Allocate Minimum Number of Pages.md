Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.  
Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

---
$O(N * log(S))$
```cpp
int countStudents(vector<int>& v, int pages){
    int students=1;
    long long pagesStudent=0;
    for (int i = 0; i < v.size(); ++i)
    {
        if(v[i]+pagesStudent <= pages){
            //add pages  to the current student
            pagesStudent+=v[i];
        }
        else{
            //move to the new student and add pages
            students++;
            pagesStudent=v[i];
        }
    }
    return students;
}

int findPages(vector<int>& A, int n, int m){
    if(n<m) return -1;
    int low=*max_element(A.begin(),A.end());
    int high=accumulate(A.begin(),A.end(),0);
    while (low <= high) {
        int mid = (low + high) / 2; 
        if(countStudents(A,mid)>m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
```