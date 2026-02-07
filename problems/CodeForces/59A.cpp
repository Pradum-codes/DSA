#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;

    int u = 0, l = 0;
    for(char c : s) {
        if(isupper(c)) u++;
        else l++;
    }

    for(char &c : s) {
        c = (l >= u) ? tolower(c) : toupper(c);
    }

    cout << s << endl;
    return 0;
}
