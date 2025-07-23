#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // Count the important reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; ++i) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                ++j;
            }
            count += (j - (mid + 1));
        }

        // Merge the two sorted halves
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; ++i) {
            nums[i] = temp[i - low];
        }

        return count;
    }
};


// TLE
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 long long ni = nums[i];
//                 long long nj = nums[j];
//                 if(ni > 2*nj){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.reversePairs(nums);
}