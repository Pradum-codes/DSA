#include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
    
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    stk.push(s[i]);
                } else {
                    if (stk.empty()) {
                        return false;
                    }
                    char top = stk.top();
                    if ((s[i] == ')' && top != '(') ||
                        (s[i] == '}' && top != '{') ||
                        (s[i] == ']' && top != '[')) {
                        return false;
                    }
                    stk.pop();
                }
            }
    
            return stk.empty();
        }
};

int main() {
    string str = "()";
    Solution obj;
    bool valid = obj.isValid(str);
    cout << valid;
    return 0;
}