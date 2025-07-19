#include <iostream>
#include <climits>
using namespace std;

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Cast before any negation
        long long ldividend = dividend;
        long long ldivisor = divisor;

        // Determine the sign
        bool isNegative = (ldividend < 0) ^ (ldivisor < 0);

        // Convert to positive after casting to avoid overflow
        ldividend = ldividend < 0 ? -ldividend : ldividend;
        ldivisor = ldivisor < 0 ? -ldivisor : ldivisor;

        long long result = 0;

        while (ldividend >= ldivisor) {
            long long temp = ldivisor, multiple = 1;
            while ((temp << 1) <= ldividend) {
                temp <<= 1;
                multiple <<= 1;
            }
            ldividend -= temp;
            result += multiple;
        }

        return isNegative ? -result : result;
    }
};
// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if (dividend == INT_MIN && divisor == -1) {
//             return INT_MAX;
//         }

//         long long ldividend = static_cast<long long>(dividend);
//         long long ldivisor = static_cast<long long>(divisor);

//         bool isNeg = (ldividend < 0) ^ (ldivisor < 0);

//         ldividend = abs(ldividend);
//         ldivisor = abs(ldivisor);

//         long long result = ldividend / ldivisor;

//         return isNeg ? -result : result;
//     }
// };

int main() {
    int divi, div;
    cin >> divi >> div;

    Solution sol;
    cout << sol.divide(divi, div) << endl;
}
