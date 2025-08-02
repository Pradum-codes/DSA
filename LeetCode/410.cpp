#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int partitions = canWeSplit(nums, mid);

            if (partitions <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int canWeSplit(vector<int>& nums, int maxSum) {
        int partitions = 1;
        int subSum = 0;

        for (int num : nums) {
            if (subSum + num > maxSum) {
                partitions++;
                subSum = num;
            } else {
                subSum += num;
            }
        }

        return partitions;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.splitArray(nums, k) << endl;
    return 0;
}
