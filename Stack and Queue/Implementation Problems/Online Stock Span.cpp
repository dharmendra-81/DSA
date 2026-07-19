class StockSpanner {
    stack<pair<int, int>> st;
    int ind;

public:
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind += 1;
        int ans = 1;
        
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};

