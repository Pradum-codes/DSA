#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> hashT;
        hashT[0] = 1;

        cout << hashT.end() << endl;

        for(int i : nums){
            sum += i;
            if(hashT.find(sum - k) != hashT.end()){
                count += hashT[sum -k];
            }

            hashT[sum]++;
        }

        return count;
    }

};


int main() {
    Solution sol;
    vector<int> arr;
    arr = {1,2,3};
    int k = 3;
    cout << sol.subarraySum(arr, k);
    return 0;
}