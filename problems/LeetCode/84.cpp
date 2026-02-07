#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> next_sr(n);
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) {
                next_sr[i] = n;
            } else {
                next_sr[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        vector<int> next_sl(n);
        for(int i = 0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) {
                next_sl[i] = -1;
            } else {
                next_sl[i] = st.top();
            }
            st.push(i);
        }

        int res = INT_MIN;

        for(int i = 0; i<n; i++){
            int area = heights[i] * (next_sr[i] - next_sl[i] - 1);
            res = max(res, area);
        }

        for(int i = 0; i<n; i++) cout << next_sr[i] << " ";
        cout << endl;
        for(int i = 0; i<n; i++) cout << next_sl[i] << " ";
        
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
       
    Solution sol;
    cout << sol.largestRectangleArea(nums) << endl;
    return 0;
}
