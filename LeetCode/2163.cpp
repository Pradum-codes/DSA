#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// OPTIMIZED
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        // Step 1: Calculate left prefix minimums using max-heap
        priority_queue<int> maxHeap;
        long long leftSum = 0;
        vector<long long> leftMinSums(3 * n, 0);

        for (int i = 0; i < n; ++i) {
            leftSum += nums[i];
            maxHeap.push(nums[i]);
        }
        leftMinSums[n - 1] = leftSum;

        for (int i = n; i < 2 * n; ++i) {
            leftSum += nums[i];
            maxHeap.push(nums[i]);
            leftSum -= maxHeap.top(); // Remove largest to keep only n smallest
            maxHeap.pop();
            leftMinSums[i] = leftSum;
        }

        // Step 2: Calculate right suffix maximums using min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        vector<long long> rightMaxSums(3 * n, 0);

        for (int i = 3 * n - 1; i >= 2 * n; --i) {
            rightSum += nums[i];
            minHeap.push(nums[i]);
        }
        rightMaxSums[2 * n] = rightSum;

        for (int i = 2 * n - 1; i >= n; --i) {
            rightSum += nums[i];
            minHeap.push(nums[i]);
            rightSum -= minHeap.top(); // Remove smallest to keep only n largest
            minHeap.pop();
            rightMaxSums[i] = rightSum;
        }

        // Step 3: Find minimum difference between left and right
        long long result = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            result = min(result, leftMinSums[i] - rightMaxSums[i + 1]);
        }

        return result;
    }
};


// class Solution {
// public:
//     long long minimumDifference(vector<int>& nums) {
//         int totalSize = nums.size();
//         int n = totalSize / 3;
//         vector<int> indices(totalSize, 1); // 1 means keep, 0 means remove
//         fill(indices.begin(), indices.begin() + n, 0); // Mark n indices to remove

//         long long minDiff = LLONG_MAX;

//         do {
//             vector<int> kept;
//             for (int i = 0; i < totalSize; ++i) {
//                 if (indices[i] == 1) {
//                     kept.push_back(nums[i]);
//                 }
//             }

//             // Valid only if kept size is 2n
//             if (kept.size() != 2 * n) continue;

//             long long leftSum = 0;
//             long long rightSum = 0;

//             for (int i = 0; i < n; ++i) {
//                 leftSum += kept[i];
//             }
//             for (int i = n; i < 2 * n; ++i) {
//                 rightSum += kept[i];
//             }

//             long long diff = leftSum - rightSum;
//             minDiff = min(minDiff, diff);

//         } while (next_permutation(indices.begin(), indices.end()));

//         return minDiff;
//     }
// };

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.minimumDifference(nums) << endl;

    return 0;
}
