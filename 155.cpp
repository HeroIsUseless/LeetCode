class MinStack {
    int n;
    int *arr;
public:
    MinStack() {
        n=0;
        arr = new int[1000];
    }
    
    void push(int x) {
        if(n+1 > 1000) return;
        arr[n++] = x;
    }
    
    void pop() {
        if(n-1 < 0) return;
        n--;
    }
    
    int top() {
        if(n-1 < 0) return 0;
        return arr[n-1];
    }
    
    int getMin() {
        if(n == 0) return 0;
        int res = arr[0];
        for(int i=0; i<n; i++){
            if(res > arr[i]) res = arr[i];
        }
        return res;
    }
};
