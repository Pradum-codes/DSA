#include <iostream>
using namespace std;

int main() {
    int n, b, d;
    cin >> n >> b >> d;

    int container = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int orange;
        cin >> orange;

        if (orange <= b) {
            container += orange;
            if (container > d) {
                count++;
                container = 0;
            }
        }
    }

    cout << count << endl;
    return 0;
}
