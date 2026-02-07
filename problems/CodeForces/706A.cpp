#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    double minTime = 1e9; // A large number

    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;

        double dist = sqrt((x - a) * 1.0 * (x - a) + (y - b) * 1.0 * (y - b));
        double time = dist / v;

        minTime = min(minTime, time);
    }

    cout << fixed << setprecision(10) << minTime << endl;
    return 0;
}
