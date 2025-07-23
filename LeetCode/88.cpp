#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// MORE OPTIMIZED
// Time: O(m + n)
// Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};

// OPTIMIZED
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> res;
//         int i = 0, j = 0;
//         while(i<m && j<n){
//             if(nums1[i] <= nums2[j]){
//                 res.push_back(nums1[i++]);
//             } else {
//                 res.push_back(nums2[j++]);
//             }
//         }
//         while(i<m){
//             res.push_back(nums1[i++]);
//         }
//         while(j<n){
//             res.push_back(nums2[j++]);
//         }

//         for(int i = 0; i<res.size(); i++){
//             nums1[i] = res[i];
//         }
//     }
// };

// O(n*logn)

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int i = 0; i<n; i++){
//             nums1[m+i] = nums2[i];
//         }

//         sort(nums1.begin(), nums1.end());
//     }
// };

int main() {
    int m;
    int n;

    vector<int> nums1(m);
    vector<int> nums2(n);

    for(int i = 0; i<m; i++){
        cin >> nums1[i];
    }
    for(int i = 0; i<n; i++){
        cin >> nums2[i];
    }
    
    Solution sol;
    sol.merge(nums1,m,nums2,n);
    for(int i = 0; i<m; i++){
        cout << nums1[i];
    }

    return 0;
}