#include <iostream>
#include <vector>

using namespace std;

// OPTIMIZED Dutch-National-Flag-Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> count(3);
//         for(int i = 0; i < n; i++){
//             count[nums[i]]++;
//         }
//         int ind = 0;
//         for(int i = 0; i < count[0]; i++){
//             nums[ind++] = 0;
//         }
//         for(int i = 0; i < count[1]; i++){
//             nums[ind++] = 1;
//         }
//         for(int i = 0; i < count[2]; i++){
//             nums[ind++] = 2;
//         }
//     }
// };

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i < n-1; i++){
//             for(int j = 0; j < n-i-1; j++){
//                 if(nums[j] > nums[j+1]){
//                     swap(nums[j], nums[j+1]);
//                 }
//             }
//         }
//     }
// };

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    Solution sol;
    sol.sortColors(arr);
    cout << endl;
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}