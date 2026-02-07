#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0; i < n - 1; i++) {
            if(i % 2 == 0){
                if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
            } else {
                if(arr[i] < arr[i+1]) swap(arr[i], arr[i+1]);
            }
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