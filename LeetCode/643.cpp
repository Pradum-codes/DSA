#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = k;

        double sum = 0;
        for(int l = 0; l<k; l++) sum += nums[l];

        double avg = sum/k;

        while(j<n){
            sum = sum - nums[i++] + nums[j++];
            avg = max(avg, sum/k);
        }

        return avg;
    }
};

int main() {
    int n,k; cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.findMaxAverage(nums, k) << endl;

    return 0;
}
