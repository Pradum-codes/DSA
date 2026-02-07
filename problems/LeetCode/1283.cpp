#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = 1;
        int n = nums.size();
        for(int i = 0;i<n; i++) maxi = max(maxi, nums[i]);
        int l = 1;
        int r = maxi;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }

            if (sum <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};


// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int divisor = 1;
        
//         while (true) {
//             int sum = 0;
//             for (int i = 0; i < nums.size(); ++i) {
//                 sum += (nums[i] + divisor - 1) / divisor;
//             }

//             if (sum <= threshold) break;
//             divisor++;
//         }

//         return divisor;
//     }
// };

int main() {
    int n, th;
    cin >> n >> th;

    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.smallestDivisor(nums, th);
}