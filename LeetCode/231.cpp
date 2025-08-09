#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Handle edge case where n is not positive
        if (n <= 0) {
            return false;
        }

        // A number is a power of two if it has exactly one bit set in its binary representation
        // This is equivalent to saying n & (n - 1) should be zero
        return (n & (n - 1)) == 0;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    if(sol.isPowerOfTwo(n)){
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    return 0;
}