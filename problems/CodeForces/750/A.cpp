#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int timeLeft = 240 - k;
    int total = 0;
    int res = 0;

    for (int i = 1; i <= n; i++) {
        total += 5 * i;
        if (total > timeLeft) break;
        res++;
    }

    cout << res << endl;
    return 0;
}
