#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;    
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int num : nums2){
            ++cnt[num];
        }
    }
    
    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (int num : nums1) {
            int rest = tot - num;
            if (cnt.count(rest)) {
                ans += cnt[rest];
            }
        }
        return ans;
    }
};

int main() {
    // Initialize vectors directly with values
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};
    
    // Alternative: Read from input
    // int n1, n2;
    // cin >> n1 >> n2;
    // vector<int> nums1(n1), nums2(n2);
    // for(int i = 0; i < n1; i++){
    //     cin >> nums1[i];
    // }
    // for(int i = 0; i < n2; i++){  // Fixed: use n2 instead of n1
    //     cin >> nums2[i];
    // }
    
    FindSumPairs obj(nums1, nums2);  // Use stack allocation instead of heap
    
    cout << obj.count(7) << " ";     // Output: 8
    obj.add(3, 2);              // nums2 becomes [1, 4, 5, 4, 5, 4]
    cout << obj.count(8) << " ";     // Output: 2
    cout << obj.count(4) << " ";     // Output: 1
    obj.add(0, 1);                   // nums2 becomes [2, 4, 5, 4, 5, 4]
    obj.add(1, 1);                   // nums2 becomes [2, 5, 5, 4, 5, 4]
    cout << obj.count(7) << " ";     // Output: 11

    cout << endl;
    return 0;
}