#include <iostream>

using namespace std;

// OPTIMIZED
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;

        long long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1;
        while(N > 0) {
            if(N % 2 == 1) result *= x;
            x *= x;
            N /= 2;
        }
        return result;
    }
};

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(n==1) return x;
//         return x * myPow(x,n-1);
//     }
// };

int main(){
    double x;
    int n;
    cin >> x >> n;

    Solution sol;
    cout << sol.myPow(x,n);
}