#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                arr.push_back(nums[i]);
            }
        }

        int count = 0;
        for (int i = 1; i < arr.size() - 1; ++i) {
            if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || 
                (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    Solution sol;
    cout << sol.countHillValley(nums) << endl;

    return 0;
}
