#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;
        while(right<nums.size()){
            if(nums[right] == nums[left]){
                right++;
            } else {
                nums[left+1] = nums[right];
                left++;
            }
        }
        int count = left;
        return count+1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    Solution sol;
    cout << "Unique: " << sol.removeDuplicates(arr) << endl;
    
    for(int i = 0; i<n; i++){
        cout << arr[i] << endl;
    }
}