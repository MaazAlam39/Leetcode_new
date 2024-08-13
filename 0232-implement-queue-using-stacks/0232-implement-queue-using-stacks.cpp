class MyQueue {
public:
stack<int>input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        //if(output.empty()==false)output.pop();
        if(output.empty()){
            while(! input.empty()){
                output.push(input.top());
                input.pop();
            }
            }
        int a=output.top();
        output.pop();
        return a;
        
    }
    
    int peek() {
        int ans=pop();
        output.push(ans);
        return ans;
    }
    
    bool empty() {
       return input.empty() && output.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */