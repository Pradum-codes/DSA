#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);

        if (lb < nums.size() && nums[lb] == target) {
            res[0] = lb;
            res[1] = ub - 1;
        }

        return res;
    }

    int lowerBound(const vector<int>& nums, int x) {
        int ind = nums.size();
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] >= x) {
                ind = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ind;
    }

    int upperBound(const vector<int>& nums, int x) {
        int ind = nums.size();
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > x) {
                ind = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ind;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int x;
    cin >> x;

    Solution sol;
    vector<int> res = sol.searchRange(nums, x);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}
