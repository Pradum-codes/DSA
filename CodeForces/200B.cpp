#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    double val = 0;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        val += ele / 100.0;
    }

    cout << fixed << setprecision(12) << (val / n) * 100 << endl; 
}