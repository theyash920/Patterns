class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
    MinStack() {    
    }
    
    void push(int val) {
        st.push(val);

        if(minStack.empty() || val <= minStack.top()){     
            minStack.push(val);
        }
    }
    
    void pop() {
        int poppedValue = st.top();      
        st.pop();                       
        if(poppedValue == minStack.top()){   
            minStack.pop();
        }
        
    }
    
    int top() {
        return st.top(); 
    }    
    
    int getMin() {
        return minStack.top();    
        
    }
    
};