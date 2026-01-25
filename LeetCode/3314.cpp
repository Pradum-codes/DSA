#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            for (int j = 1; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                    break;
                }
            }
            if (nums[i] == tmp) {
                nums[i] = -1;
            }
        }
        return nums;
    }
};


int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++) cin >> arr[i];

    Solution sol;
    vector<int> ans = sol.minBitwiseArray(arr);
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}