#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int l = 0;
        int r = l + k - 1;
        int count = 0;

        while (r < n) {
            bool isRaining = false;
            int rainyDay = -1;

            for (int i = l; i <= r; i++) {
                if (arr[i] == 1) {
                    isRaining = true;
                    rainyDay = i;
                    break;
                }
            }

            if (isRaining) {
                l = rainyDay + 1;
                r = l + k - 1;
            } else {
                count++;
                l = r + 2;
                r = l + k - 1;
            }
        }

        cout << count << endl;
    }

    return 0;
}
