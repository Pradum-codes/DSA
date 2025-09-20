#include <bits/stdc++.h>
using namespace std;

// IMPROVED O(Nlogm);
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;  // Vector instead of stack for better performance

        for (int num : nums) {
            while (!stack.empty()) {
                int top = stack.back();
                int g = gcd(top, num);

                if (g == 1) break;  // Already coprime, stop merging
                
                // Compute LCM without overflow
                num = (long long)(top / g) * num;
                stack.pop_back();
            }
            stack.push_back(num);
        }
        
        return stack;
    }
};

// BRUTE-FORCE O(N log(max(nums[i])))
// class Solution {
// public:
//     vector<int> replaceNonCoprimes(vector<int>& nums) {
//         stack<int> st;
        
//         for (int num : nums) {
//             // Push the first number onto the stack
//             if (st.empty()) {
//                 st.push(num);
//                 continue;
//             }
            
//             // Merge non-coprime numbers
//             while (!st.empty()) {
//                 int top = st.top();
//                 int g = gcd(top, num);
                
//                 if (g == 1) {
//                     // They are coprime; stop merging
//                     break;
//                 }
                
//                 // Replace top and num by their LCM
//                 st.pop();
//                 num = lcm(top, num);
//             }
            
//             st.push(num);
//         }
        
//         // Collect the result in correct order
//         vector<int> result(st.size());
//         for (int i = st.size() - 1; i >= 0; --i) {
//             result[i] = st.top();
//             st.pop();
//         }
        
//         return result;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    Solution sol;
    vector<int> res = sol.replaceNonCoprimes(nums);
    
    for (int num : res)
        cout << num << " ";
    cout << "\n";
    
    return 0;
}
