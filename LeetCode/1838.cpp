#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int left = 0;
        int result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left];
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;

    cout << sol.maxFrequency(arr,k) << endl;
}