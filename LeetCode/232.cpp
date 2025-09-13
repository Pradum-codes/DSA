#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> original;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!original.empty()) {
            int org_s = original.size();
            while(org_s != 0) {
                int val = original.top();
                helper.push(val);
                original.pop();
                org_s--;
            }
            helper.push(x);
        } else {
            helper.push(x);
        }
        
        int help_s = original.size();
        while(help_s!=0) {
            original.push(helper.top());
            helper.pop();
            help_s--;
        }
    }
    
    int pop() {
        if(!original.empty()){
            int val = original.top();
            original.pop();
            return val;
        }
    }
    
    int peek() {
        if(!original.empty()){
            int val = original.top();
            return val;
        }
    }
    
    bool empty() {
        return original.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    MyQueue qu;
    
    return 0;
}