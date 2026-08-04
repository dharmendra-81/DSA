class MedianFinder {
    priority_queue<int> maxHeap; // stores the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap; // stores the larger half of the numbers

public:
    MedianFinder() { }
    
    void addNum(int num) {
        //  Insert into correct heap
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        } else{
            minHeap.push(num);
        }

        //  Balance the heaps
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        return maxHeap.top();
    }
};

