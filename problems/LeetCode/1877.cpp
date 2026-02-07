#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }

        return ans;
    }
};

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++) cin >> arr[i];

    Solution sol;
    cout << sol.minPairSum(arr) << endl;
}