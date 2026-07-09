class MyStack {
    queue<int> q;
public:
    MyStack() {
 
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        for(int i = 1; i < n; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(!q.empty()){
            int top = q.front();
            q.pop();
            return top;
        } 
        return -1; 
    }
    
    int top() {
        if(!q.empty()){
            return q.front();
        }
        return -1;
    }
    
    bool empty() {
        return q.empty();
    }
};

