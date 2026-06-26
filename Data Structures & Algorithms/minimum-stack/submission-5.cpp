class MinStack {
    stack<int>st;
    stack<int>min;
    //long mint = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min.empty()||val<=min.top() ){
            min.push(val);
        }
        
    }
    
    void pop() {
       int val = st.top();
       st.pop();
       if(val==min.top()){
            min.pop();
       } 
    }
    
    int top() {
        return (int)st.top();
    }
    
    int getMin() {
        return (int)min.top();
    }
};
