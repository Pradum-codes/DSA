#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int l = 0, r = n - 1;
        long long count = 0;

        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                count = (count + pow2[r - l]) % MOD;
                l++;
            }
        }

        return count;
    }
};


int main() {
    int n, tar; cin >> n >> tar;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;

    cout << sol.numSubseq(nums, tar) << endl;

    return 0;
}

/*

14 4 6 6 20 8 5 6 8 12 6 10 14 9 17 16 9 7 14 11 14 15 13 11 10 18 13 17 17 14 17 7 9 5 10 13 8 5 18 20 7 5 5 15 19 14
*/