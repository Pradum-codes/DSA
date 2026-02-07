#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int pos = 0, neg = 1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                result[pos] = nums[i];
                pos += 2;
            } else {
                result[neg] = nums[i];
                neg += 2;
            }
        }

        return result;
    }
};


// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result(n);
//         vector<int> temp(n);
//         int l = 0;
//         int r = n/2;

//         for(int i = 0; i<n; i++){
//             if(nums[i] > 0) temp[l++] = nums[i];
//             else temp[r++] = nums[i];
//         }

//         l = 0;
//         r = n/2;
//         bool neg = false;
//         for(int i = 0; i<n; i++){
//             if(!neg) {
//                 result[i] = temp[l++];
//                 neg = !neg;
//             } else {
//                 result[i] = temp[r++];
//                 neg = !neg;
//             }
//         }

//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> first;
//         vector<int> second;
//         vector<int> result(n);
        
//         for (int i = 0; i < n; i++) {
//             if (nums[i] < 0)
//                 first.push_back(nums[i]);
//             else
//                 second.push_back(nums[i]);
//         }

//         int i = 0, j = 0, indx = 0;
//         bool neg = true;

//         while (i < second.size() || j < first.size()) {
//             if (!neg && j < first.size()) {
//                 result[indx++] = first[j++];
//                 neg = !neg;
//             } else if (neg && i < second.size()) {
//                 result[indx++] = second[i++];
//                 neg = !neg;
//             } else if (j < first.size()) {
//                 result[indx++] = first[j++];
//             } else if (i < second.size()) {
//                 result[indx++] = second[i++];
//             }
//         }

//         return result;
//     }
// };

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.rearrangeArray(nums);
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
}
