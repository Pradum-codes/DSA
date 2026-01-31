#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.length()-1;

        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        
        while(l < r){
            if(s[l] == s[r]){
                l++; 
                r--;
            } else {
                bool removeLeft = isPalindrome(s.substr(l+1, r-l));
                bool removeRight = isPalindrome(s.substr(l, r-l));
                return removeLeft || removeRight;
            }
        }
        return true;
    }
};

int main() {
    string s; cin >> s;
    Solution sol;
    if(sol.validPalindrome(s)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}

/*

*/
