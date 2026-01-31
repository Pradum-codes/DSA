#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n-1;

        while(l < r){
            if(!isalnum(s[l])){
                l++;
            }
            else if(!isalnum(s[r])){
                r--;
            }
            else{
                if(tolower(s[l]) != tolower(s[r])){
                    return false;
                }
                l++;
                r--;
            }
        }

        return true;
    }
};

// String can contain spaces special character but we want to check the alphabet only

int main() {
    string s; cin >> s;

    Solution sol;
    if(sol.isPalindrome(s)) cout << "PALINDROME" << endl;
    else cout << "NOT PALINDROME" << endl;

    return 0;
}