#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// class Solution {
// public:
//     char kthCharacter(long long k, vector<int>& operations) {
//         string word = "a";
//         if (k == 1) return 'a';
//         for(int i = 0; i<operations.size(); i++){
//             if(operations[i] == 0){
//                 word += word;
//             } else if(operations[i] == 1){
//                 string temp = "";
//                 for(int i = 0; i<word.size(); i++){
//                     temp += word[i]+1;
//                 }
//                 word+= temp;
//             }
//         }
//         cout << word << endl;

//         return word[k-1];
//     }
// };

// Optimized Recursion
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) return 'a';
        int n = operations.size();
        long long len = 1;
        long long newK = -1;
        int operationType = -1;

        for(int i = 0; i<n; i++){
            len *= 2;
            if(len >= k){
                operationType = operations[i];
                newK = k - len/2;
                break;
            }
        }
        char ch = kthCharacter(newK, operations);

        if(operationType == 0){
            return ch;
        }

        return ch == 'z' ? 'a' : ch + 1;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    long long k;
    int n;
    cin >> k >> n;
    for(int i = 0; i< n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cout << sol.kthCharacter(k,arr);
}