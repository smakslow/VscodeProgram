class MinStack {
    Stack<Integer> data;
    Stack<Integer> min;
    /** initialize your data structure here. */
    public MinStack() {
        data = new Stack<>();
        min = new Stack<>();
    }

    public void push(int x) {
        data.push(x);
        if(min.isEmpty()){
            min.push(x);
        }else if(getMin() >= x){
            min.push(x);
        }
    }

    public void pop() {
        if (data.isEmpty()) {
           throw new RuntimeException("Your stack is empty.");
        }
        if (data.pop() == getMin()) {
            min.pop();
        }
    }

    public int top() {
        return data.peek();
    }

    public int getMin() {
        if (min.isEmpty()) {
        throw new RuntimeException("Your stack is empty.");
        }
        return min.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
