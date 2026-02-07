#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res(n);
        
        int j = 0;
        for(int i = 0; i < (n + 1) / 2; i++){
            res[j] = nums[i];
            j += 2;
        }
        
        j = 1;
        for(int i = (n + 1) / 2; i < n; i++){
            res[j] = nums[i];
            j += 2;
        }
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    sol.wiggleSort(nums);

    for(int i = 0; i<n; i++) cout << nums[i] << " ";
    cout << endl;
}