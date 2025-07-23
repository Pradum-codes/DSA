#include <iostream>
#include <vector>

using namespace std;

// OPTIMIZED
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[mid] == target) return mid;

            if( nums[l] <= nums[mid] ){
                if(target >= nums[l] && target < nums[mid]){
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if(target > nums[mid] && target <= nums[r]){
                    l = mid+1;
                }else {
                    r = mid-1;
                }
            }
        }

        return  -1;
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int ind = -1;
//         int n = nums.size();
//         for(int i = 0; i<n-1; i++) {
//             if (nums[i] > nums[i+1]){
//                 ind = i;
//                 break;
//             }
//         }

//         int l = -1;
//         int r = -1;
//         if(ind != -1) {
//             if ( target >= nums[0] && target <= nums[ind]) {
//                 l = 0;
//                 r = ind;
//             } else {
//                 l = ind + 1;
//                 r = n-1;
//             }
//         } else {
//             l = 0;
//             r = n - 1;
//         }

//         while(l<=r){
//             int mid = l + (r-l)/2;
//             if(nums[mid] == target){
//                 return mid;
//             }else if(nums[mid] < target){
//                 l = mid+1;
//             } else {
//                 r = mid-1;
//             }


//         }

//         return  -1;
//     }
// };

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.search(nums, x) << endl;
}