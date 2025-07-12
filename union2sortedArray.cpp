#include <iostream>
#include <vector>
#include <set>

using namespace std;

// class Solution {
// public:
//     vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res;
//         set<int> s;
        
//         for(int i = 0; i < nums1.size(); i++){
//             s.emplace(nums1[i]);
//         }
        
//         for(int i = 0; i < nums2.size(); i++){
//             s.emplace(nums2[i]);
//         }
        
//         for(auto it : s) {
//             res.push_back(it);  // Use push_back instead of index access
//         }
        
//         return res;
//     }
// };

//OPTIMIZED
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                if(res.size() == 0 || res.back() != nums1[i]){
                    res.push_back(nums1[i]);
                }
                i++;
            } else {
                if(res.size() == 0 || res.back() != nums2[j]){
                    res.push_back(nums2[j]);
                }
                j++;
            }
        }

        while(i < nums1.size()){
            if(res.size() == 0 || res.back() != nums1[i]){
                res.push_back(nums1[i]);
            }
            i++;
        }
        
        while(j < nums2.size()){
            if(res.size() == 0 || res.back() != nums2[j]){
                res.push_back(nums2[j]);
            }
            j++;
        }
        
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 7, 7};

    Solution sol;
    vector<int> result = sol.unionArray(nums1, nums2);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}