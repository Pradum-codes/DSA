#include <iostream>
#include <set>

using namespace std;

bool sharesDigit(int x, int y) {
    set<int> digitsX;
    while (x > 0) {
        digitsX.insert(x % 10);
        x /= 10;
    }

    if (y == 0) {
        return digitsX.count(0);
    }

    while (y > 0) {
        if (digitsX.count(y % 10)) return true;
        y /= 10;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        for (int y = 0; y <= 1000; y++) {
            if (sharesDigit(x, y)) {
                cout << y << endl;
                break;
            }
        }
    }

    return 0;
}
