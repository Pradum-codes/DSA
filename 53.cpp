class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int current_sum = 0;

        for (int num : nums) {
            current_sum = std::max(num, current_sum + num);
            max_sum = std::max(max_sum, current_sum);
        }

        return max_sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, -3, 2, 3, -4};
    vector<int> nums2 = {2, -5, 1, -4, 3, -2};
    cout << "Output 1: " << sol.maxSubArray(nums1) << endl;
    cout << "Output 2: " << sol.maxSubArray(nums2) << endl;

    return 0;
}