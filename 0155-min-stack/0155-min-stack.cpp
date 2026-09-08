class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
    }

    void push(int val) {
        long long value = val;

        if (st.empty()) {
            mini = value;
            st.push(value);
        }
        else {
            if (value < mini) {
                st.push(2LL * value - mini);
                mini = value;
            }
            else {
                st.push(value);
            }
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2LL * mini - x;
        }
    }

    int top() {
        long long x = st.top();

        if (x < mini)
            return mini;

        return x;
    }

    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */