// 虽然是说一个队列，但是，你要实现自己的stack，就不用。。。
class MyStack {
    int *ar;
    int n;
public:
    /** Initialize your data structure here. */
    MyStack() {
        ar = new int[10000];
        n = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        ar[n++] = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        return ar[--n];
    }
    
    /** Get the top element. */
    int top() {
        return ar[n-1];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(n==0) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */