#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int countF = 0, countT = 0, countN = 0;
        vector<char> others;

        for (char c : s) {
            if (c == 'F') countF++;
            else if (c == 'N') countN++;
            else if (c == 'T') countT++;
            else others.push_back(c);
        }

        while (countT--) cout << 'T';
        while (countF--) cout << 'F';
        while (countN--) cout << 'N';

        for (char c : others) cout << c;

        cout << endl;
    }

    return 0;
}
