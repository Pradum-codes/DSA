#include <bits/stdc++.h>
using namespace std;

// OPTIMIZED
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1); // ensure nums1 is smaller
        
        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } 
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            else {
                low = partitionX + 1;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int size1 = nums1.size();
//         int size2 = nums2.size();
//         vector<int> merged;
//         int i = 0, j = 0;

 
//         while (i < size1 && j < size2) {
//             if (nums1[i] < nums2[j]) {
//                 merged.push_back(nums1[i]);
//                 i++;
//             } else {
//                 merged.push_back(nums2[j]);
//                 j++;
//             }
//         }


//         while (i < size1) {
//             merged.push_back(nums1[i]);
//             i++;
//         }

//         while (j < size2) {
//             merged.push_back(nums2[j]);
//             j++;
//         }

//         int n = merged.size();
//         if (n % 2 == 0) {
//             return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
//         } else {
//             return merged[n / 2];
//         }
//     }
// };

/*
1 2 3 4
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1,n2; cin>>n1>>n2;
    vector<int> nums1(n1), nums2(n2);
    for (int i = 0; i < n1; i++) cin >> nums1[1];
    for (int i = 0; i < n2; i++) cin >> nums2[1];
    
    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2);
    return 0;
}