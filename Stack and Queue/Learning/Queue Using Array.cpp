class myQueue {
    int *q;
    int size;
    int currSize;
    int start;
    int end;

  public:
    myQueue(int n) {
        // Define Data Structures
        size = n;
        q = new int[n];
        currSize = 0;
        start = -1;
        end = -1;
    }

    bool isEmpty() {
        // check if the queue is empty
        return currSize == 0;
    }

    bool isFull() {
        // check if the queue is full
        return currSize == size;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) return;
        if(isEmpty()){
            start = 0;
            end = 0;
        }
        else end = (end + 1) % size;
        q[end] = x;
        currSize++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return;
        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else start = (start + 1) % size;
        currSize--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return q[start];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        return q[end];
    }
};