#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int aggressiveCows(vector<int> &nums, int k) {
//         sort(nums.begin(), nums.end());
//         int low = 1;
//         int high = nums.back() - nums.front();
//         int ans = 0;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (canWePlace(nums, mid, k)) {
//                 ans = mid;
//                 low = mid + 1;   // try for a bigger distance
//             } else {
//                 high = mid - 1;  // try for a smaller distance
//             }
//         }

//         return ans;
//     }

//     bool canWePlace(vector<int> &nums, int dist, int k) {
//         int cntCows = 1;
//         int last = nums[0];
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] - last >= dist) {
//                 cntCows++;
//                 last = nums[i];
//             }
//             if (cntCows >= k) return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int maxDist = nums.back() - nums.front();
        int ans = 0;

        for (int d = 1; d <= maxDist; d++) {
            if (canWePlace(nums, d, k)) {
                ans = d;
            }
        }

        return ans;
    }

    bool canWePlace(vector<int> &nums, int dist, int k) {
        int cntCows = 1;
        int last = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - last >= dist) {
                cntCows++;
                last = nums[i];
            }
            if (cntCows >= k) return true;
        }
        return false;
    }
};

// 0 3 4 7 9 10

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.aggressiveCows(nums, k) << endl;

    return 0;
}