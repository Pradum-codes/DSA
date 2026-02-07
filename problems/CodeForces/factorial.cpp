#include <iostream>
using namespace std;

int factorial(int num){
    if(num==1 || num==0){
        return 1;
    }
    return num*factorial(num-1);
}

int main() {
    cout << "Number: ";
    int n;
    cin >> n;

    cout << factorial(n) << endl;
    return 0;
}