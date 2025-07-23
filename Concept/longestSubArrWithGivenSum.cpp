#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     int longestSubarray(vector<int> &nums, int k) {
//         int n = nums.size();
//          int i = 0, sum = 0, ans = 0;

//          for (int j = 0; j < n; ++j) {
//              sum += nums[j];

//             while (sum > k && i <= j) {
//                 sum -= nums[i];
//                 ++i;
//             }

//             if (sum == k) {
//                 ans = max(ans, j - i + 1);
//             }
//         }

//         return ans;
//     }
// };

// OPTIMIZED
class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        unordered_map<int, int> prefixIndex;
        int sum = 0, ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (sum == k) {
                ans = i + 1;
            }

            if (prefixIndex.find(sum - k) != prefixIndex.end()) {
                ans = max(ans, i - prefixIndex[sum - k]);
            }

            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << sol.longestSubarray(arr, k);
}
