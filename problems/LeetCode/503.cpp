#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    
    Solution sol;
    vector<int> res = sol.nextGreaterElements(nums);

    for(int i = 0; i<res.size(); i++) cout << res[i] << " ";
    return 0;
}