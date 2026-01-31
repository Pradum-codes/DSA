#include <iostream>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        char ch = tolower(c);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;

        while(i<=j) {
            if(isVowel(s[i]) && isVowel(s[j])){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            else if(!isVowel(s[i])){
                i++;
            }
            else if(!isVowel(s[j])){
                j--;
            }
        }

        return s;
    }
};

int main() {
    string s; cin >> s;

    Solution sol;
    cout << sol.reverseVowels(s) << endl;
}