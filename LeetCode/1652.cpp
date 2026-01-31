#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if(k == 0) {
            return res;
        }

        if(k > 0) {
            int sum = 0;
            for(int i = 1; i <= k; i++){
                sum += code[i % n];
            }
            res[0] = sum;

            for(int i = 1; i < n; i++){
                sum = sum - code[i % n] + code[(i + k) % n];
                res[i] = sum;
            }
        }

        if(k < 0) {
            int sum = 0;
            for(int i = 1; i <= -k; i++){
                sum += code[(n - i) % n];
            }
            res[0] = sum;

            for(int i = 1; i < n; i++){
                sum = sum - code[(n + i - 1 + k) % n] + code[(i - 1) % n];
                res[i] = sum;
            }
        }
        return res;
    }
};

int main() {
    int n,k; cin>>n>>k;
    vector<int> code(n);
    for(int i = 0; i<n; i++) cin >> code[i];

    Solution sol;
    vector<int> res = sol.decrypt(code, k);
    for(int i = 0; i<n; i++) cout << res[i] << " ";

    cout<<endl;

    return 0;
}
