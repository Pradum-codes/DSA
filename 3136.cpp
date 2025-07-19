#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() >= 3) {
            if (checkCharacter(word)) {
                if (checkForvowel(word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkForvowel(const string& word) {
        int vowel = 0;
        int consonants = 0;
        for (char ch : word) {
            char c = tolower(ch);
            if (isVowel(c)) {
                vowel++;
            } else if (c >= 'a' && c <= 'z') {
                consonants++;
            }
        }
        return vowel > 0 && consonants > 0;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool checkCharacter(const string& word) {
        for (char s : word) {
            if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string str;
    cin >> str;
    Solution sol;
    cout << boolalpha << sol.isValid(str) << endl;
}
