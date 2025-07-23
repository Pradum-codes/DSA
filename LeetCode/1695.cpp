#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// OPTIMIZED O(n);
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int maxScore = 0;
        int currentScore = 0;
        int i = 0, j = 0;

        while (j < n) {
            if (s.count(nums[j])) {
                while (nums[i] != nums[j]) {
                    currentScore -= nums[i];
                    s.erase(nums[i]);
                    i++;
                }
                currentScore -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            s.insert(nums[j]);
            currentScore += nums[j];
            maxScore = max(maxScore, currentScore);
            j++;
        }

        return maxScore;
    }
};

// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int score = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             unordered_set<int> s;
//             int currentScore = 0;

//             for (int j = i; j < n; j++) {
//                 if (s.find(nums[j]) != s.end()) {
//                     break;
//                 }
//                 s.insert(nums[j]);
//                 currentScore += nums[j];
//                 score = max(score, currentScore);
//             }
//         }

//         return score;
//     }
// };

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.maximumUniqueSubarray(nums) << endl;

}