#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i+1) % n]) {
                count++;
            }
        }

        return count <= 1;
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
    cout << sol.check(arr) << endl;
    
    return 0;
}