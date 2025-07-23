#include <iostream>
#include <vector>

using namespace std;

// optimized
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int writeIndex = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        for(int i = writeIndex; i < n; i++){
            nums[i] = 0;
        }
    }
};
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int i = 0;
//         int j = i + 1;
//         vector<int> temp;
//         while(i<n){
//             if(nums[i] != 0){
//                 temp.push_back(nums[i]);
//             }
//             i++;
//         }
//         for(int i = 0; i < temp.size(); i++){
//             nums[i] = temp[i];
//         }
//         for(int i = temp.size(); i<n; i++){
//             nums[i] = 0;
//         }
//     }
// };

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol;
    sol.moveZeroes(arr);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}