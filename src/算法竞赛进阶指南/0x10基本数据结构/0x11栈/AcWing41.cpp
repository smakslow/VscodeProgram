#include<stack>
#include<algorithm>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    #define LL long long
    stack<LL> st;
    LL min_value;

    MinStack() {

    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            min_value = x;
        } else {
            st.push(x - min_value);
            min_value = min(min_value, (LL)(x));
        }
    }

    void pop() {
        if (st.top() < 0)
            min_value -= st.top();

        st.pop();
    }

    int top() {
        if (st.size() == 1)
            return st.top();
        else if (st.top() > 0)
            return min_value + st.top();
        else
            return min_value;
    }

    int getMin() {
        return min_value;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */