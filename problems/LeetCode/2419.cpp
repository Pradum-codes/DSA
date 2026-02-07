#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxLength = 0, currLength = 0;

        for (int num : nums) {
            if (num == maxVal) {
                currLength++;
                maxLength = max(maxLength, currLength);
            } else {
                currLength = 0;
            }
        }
        return maxLength;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.longestSubarray(nums) << endl;
    return 0;
}