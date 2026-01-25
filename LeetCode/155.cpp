#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
            return;
        }

        int mini = min(getMin(), val);
        st.push({val, mini});
        return;
    }
    
    void pop() {        
        st.pop();

    }
    
    int top() {
        pair<int, int> val = st.top();
        return val.first;
    }
    
    int getMin() {
        pair<int, int> val = st.top();
        return val.second;        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->pop();
    obj->push(5);
    obj->push(-3);
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}