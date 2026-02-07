#include <iostream>
#include <vector>
using namespace std;

vector<int> primes = {2, 3, 5, 7};

unsigned long long count_multiples(unsigned long long l, unsigned long long r, unsigned long long d) {
    return r / d - (l - 1) / d;
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    return b ? gcd(b, a % b) : a;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return a / gcd(a, b) * b;
}

unsigned long long count_not_good(unsigned long long l, unsigned long long r) {
    unsigned long long count = 0;
    int n = primes.size();

    for (int mask = 1; mask < (1 << n); ++mask) {
        unsigned long long curr_lcm = 1;
        int bits = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                curr_lcm = lcm(curr_lcm, primes[i]);
                bits++;
            }
        }

        if (curr_lcm > r) continue;

        unsigned long long multiples = count_multiples(l, r, curr_lcm);
        if (bits % 2 == 1)
            count += multiples;
        else
            count -= multiples;
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        unsigned long long l, r;
        cin >> l >> r;

        unsigned long long total = r - l + 1;
        unsigned long long not_good = count_not_good(l, r);
        unsigned long long good = total - not_good;
        cout << good << '\n';
    }

    return 0;
}
