//  Time: O(nlogk2) & Space: O(k2)
class Solution {
public:
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        priority_queue<int> maxHeap;
        
        // Maintain a max-heap of size k2 to store the smallest k2 elements
        for (int num : arr) {
            maxHeap.push(num);
            if (maxHeap.size() > k2) {
                maxHeap.pop();
            }
        }
        
        // The root is the k2-th smallest element; pop it to exclude it
        maxHeap.pop();
        
        long long sum = 0;
        // Sum the next (k2 - k1 - 1) elements, which lie strictly between k1-th and k2-th
        for (int i = 0; i < k2 - k1 - 1; i++) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        
        return (int)sum;
    }
};