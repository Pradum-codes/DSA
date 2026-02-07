#include <bits/stdc++.h>
using namespace std;

// OPTIMAL
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        
        for (int num : nums) {
            if (num == 0) {
                count++;           // extend zero streak
                ans += count;      // add new subarrays ending here
            } else {
                count = 0;         // reset streak
            }
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long ans = 0;
//         int n = nums.size();
//         int j = 0;

//         while (j < n) {
//             if (nums[j] == 0) {
//                 long long count = 0;
//                 while (j < n && nums[j] == 0) {
//                     count++;
//                     j++;
//                 }
//                 ans += (count * (count + 1)) / 2;
//             } else {
//                 j++;
//             }
//         }

//         return ans;
//     }
// };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.zeroFilledSubarray(nums);
    
    return 0;
}