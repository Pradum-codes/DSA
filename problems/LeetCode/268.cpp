#include <iostream>
#include <vector>

using namespace std;

// XOR method

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int x1 = 0;
//         int x2 = 0;
//         for(int i = 0; i<n; i++){
//             x1 = x1^nums[i];
//             x2 = x2^(i+1);
//         }

//         return x1^x2;
//     }
// };

// Sum Method

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        for(int i = 0; i<n; i++){
            sum -= nums[i];
        }

        return sum;
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
    cout << sol.missingNumber(arr) << endl;
}

/*
[9,6,4,2,3,5,7,0,1]
it should contain 9 numbers as the size is 9
*/