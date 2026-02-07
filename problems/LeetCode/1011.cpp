#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int totalDays = checkDays(mid, weights);
            if (totalDays <= days) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int checkDays(int cap, vector<int>& weights) {
        int totalDays = 1;
        int currSum = 0;
        for (int w : weights) {
            if (currSum + w > cap) {
                totalDays++;
                currSum = 0;
            }
            currSum += w;
        }
        return totalDays;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, days;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.shipWithinDays(nums, days) << endl;
    return 0;
}