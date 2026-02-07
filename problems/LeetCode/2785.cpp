#include <bits/stdc++.h>
using namespace std;


// OPTIMIZED
class Solution {
public:
        string sortVowels(string s) {
        // Step 1: Count vowel frequencies
        unordered_map<char, int> freq;
        for (char c : s) {
            if (isVowel(c)) {
                freq[c]++;
            }
        }

        // Step 2: Ordered vowels string
        string sortedVowels = "AEIOUaeiou";
        string result = s;  // Work in-place for clarity

        int j = 0;  // Pointer in sortedVowels

        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                // Find the next vowel in sorted order with non-zero frequency
                while (freq[sortedVowels[j]] == 0) {
                    j++;
                }
                result[i] = sortedVowels[j];
                freq[sortedVowels[j]]--;
            }
        }

        return result;
    }

    bool isVowel(char c) {
        c = tolower(c);
        string vowel = "aeiou";
        return vowel.find(c) != string::npos;
    }
};

// BETTER

// class Solution {
// public:
//     string sortVowels(string s) {
//         vector<int> vowelIndices;
//         vector<char> vowels;

//         // Step 1: Collect vowel indices and vowel characters
//         for (int i = 0; i < s.size(); ++i) {
//             if (isVowel(s[i])) {
//                 vowelIndices.push_back(i);
//                 vowels.push_back(s[i]);
//             }
//         }

//         // Step 2: Sort the vowels
//         sort(vowels.begin(), vowels.end());

//         // Step 3: Place sorted vowels back into the original string
//         for (int i = 0; i < vowelIndices.size(); ++i) {
//             s[vowelIndices[i]] = vowels[i];
//         }

//         return s;
//     }

//     bool isVowel(char c) {
//         c = tolower(c);
//         string vowel = "aeiou";
//         return vowel.find(c) != string::npos;
//     }
// };

// BRUTE_FORCE

// class Solution {
// public:
//     string sortVowels(string s) {
//         vector<char> vowels;
//         for (char c : s) {
//             if (isVowel(c)) {
//                 vowels.push_back(c);
//             }
//         }
        
//         sort(vowels.begin(), vowels.end());
        
//         int vowelIdx = 0;
//         for (int i = 0; i < s.size(); i++) {
//             if (isVowel(s[i])) {
//                 s[i] = vowels[vowelIdx++];
//             }
//         }
        
//         return s;
//     }

//     bool isVowel(char c) {
//         c = tolower(c);
//         string vowel = "aeiou";
//         return vowel.find(c) != string::npos;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    Solution sol;
    cout << sol.sortVowels(s) << endl;
    return 0;
}
