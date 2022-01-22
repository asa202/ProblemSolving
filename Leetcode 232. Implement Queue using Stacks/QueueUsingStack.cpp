class MyQueue {
public:
    // amortized O(1) time 
    vector<int> stack;
    int firstElementIdx;
    MyQueue() {
        stack = vector<int>{};
        firstElementIdx = 0;
    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    int pop() {
        return stack[firstElementIdx++];
    }
    
    int peek() {
        return stack[firstElementIdx];
    }
    
    bool empty() {
       if(stack.size() <= firstElementIdx){
           stack = vector<int>{};
           firstElementIdx = 0;
           return true;
       }
        return false;
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