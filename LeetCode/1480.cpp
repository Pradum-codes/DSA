#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size() < 2) return nums;
        vector<int> res(nums.size());
        res[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            res[i] = res[i-1] + nums[i];
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) cin >> arr[i];

    Solution sol;
    vector<int> res = sol.runningSum(arr);

    for(int i = 0; i<n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}