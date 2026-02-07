#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for (int i = 0; i < n && s[i] == '<'; ++i) {
        cnt++;
    }
    for (int i = n - 1; i >= 0 && s[i] == '>'; --i) {
        cnt++;
    }
    std::cout << cnt << std::endl;
    return 0;
}