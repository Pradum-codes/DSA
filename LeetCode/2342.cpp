#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, pair<int, int>> sumOfDigits; // key: sum of digits, value: {largest, secondLargest}
        int maxSum = -1;

        for(int num : nums){
            int temp = num, sum = 0;

            // Calculate sum of digits
            while(temp != 0){
                sum += temp % 10;
                temp /= 10;
            }

            // Update largest and second largest numbers
            if (sumOfDigits.find(sum) == sumOfDigits.end()) {
                sumOfDigits[sum] = {num, -1}; // First occurrence
            } else {
                int first = sumOfDigits[sum].first;
                int second = sumOfDigits[sum].second;

                if (num > first) { // New largest number
                    sumOfDigits[sum] = {num, first};
                } else if (num > second) { // New second largest number
                    sumOfDigits[sum].second = num;
                }
            }
        }

        // Find the maximum sum of valid pairs
        for (auto& entry : sumOfDigits) {
            int key = entry.first;
            pair<int, int> value = entry.second;

            if (value.second != -1) { // Check if a valid pair exists
                maxSum = max(maxSum, value.first + value.second);
            }
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {18, 43, 36, 13, 7}; // Test case
    int solution = sol.maximumSum(arr);
    cout << "Maximum Sum: " << solution << endl; // Expected Output: 54
    return 0;
}


// 2342. Max Sum of a Pair With Equal Sum of Digits
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed array nums consisting of positive integers. 
// You can choose two indices i and j, such that i != j, and the sum of 
// digits of the number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over 
// all possible indices i and j that satisfy the conditions.

 

// Example 1:

// Input: nums = [18,43,36,13,7]
// Output: 54
// Explanation: The pairs (i, j) that satisfy the conditions are:
// - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
// - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
// So the maximum sum that we can obtain is 54.
// Example 2:

// Input: nums = [10,12,19,14]
// Output: -1
// Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109