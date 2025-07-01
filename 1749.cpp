class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currentMax = 0, currentMin = 0;
        int maxSum = 0, minSum = 0;

        for(int num : nums){
            currentMax = max(num, currentMax + num);
            currentMin = min(num, currentMin + num);

            maxSum = max(maxSum, currentMax);
            minSum = min(minSum, currentMin);
        }

        return max(maxSum, abs(minSum));
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1, -3, 2, 3, -4};
    vector<int> nums2 = {2, -5, 1, -4, 3, -2};
    cout << "Output 1: " << sol.maxAbsoluteSum(nums1) << endl;
    cout << "Output 2: " << sol.maxAbsoluteSum(nums2) << endl;

    return 0;
}