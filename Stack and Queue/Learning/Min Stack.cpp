// Using pair to store the minimum value in the stack
class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() { }  

    void push(int value) {
        if(st.empty()) st.push({value, value});
        else{
            int mini = st.top().second;
            st.push({value, min(value, mini)});
        }
    }

    void pop() {
        if(st.empty()) return;
        st.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top().first;
    }

    int getMin() {
        if(st.empty()) return -1;
        return st.top().second;
    }
};


// Using encoding technique to store the minimum value in the stack
class MinStack {
    // encoded = 2 x val - prevMin
    stack<long long> st;
    long long mini;
public:
    MinStack() { }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            if(value >= mini) st.push(value);
            else{
                st.push(2LL*value - mini);
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long top = st.top();
        st.pop();
        if(top < mini) mini = 2LL*mini - top;
    }
    
    int top() {
        if(st.empty()) return -1;
        long long top = st.top();
        if(top < mini) return (int)mini;
        return (int)top;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return (int)mini;
    }
};

