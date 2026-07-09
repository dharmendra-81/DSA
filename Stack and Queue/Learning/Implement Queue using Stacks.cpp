class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}
    
    void push(int x) {
       s1.push(x); 
    }
    
    int pop() {
        int val;
       if(!s2.empty()){
        val = s2.top();
        s2.pop();
       }
       else{
        // s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        val = s2.top();
        s2.pop();
       } 
       return val;
    }
    
    int peek() {
        if(!s2.empty()){
        return s2.top();
       }
       else{
        // s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
       } 
       return -1;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

