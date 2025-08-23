#include <iostream>

using namespace std;

int main() {
    int a,b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    a = a ^ b; // Step-1
    b = a ^ b; // Step-2
    a = a ^ b; // Step-3

    cout << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

/*
Suppose:

a = 13 (1101 in binary)
b = 6  (0110 in binary)

Step 1: a = a ^ b
a = 1101
b = 0110
------------
a = 1011   (11 in decimal)


Now a stores a ^ b.

Step 2: b = a ^ b

At this point, a = a ^ b.

b = (a ^ b) ^ b
  = a ^ (b ^ b)
  = a ^ 0
  = a


Binary:

a = 1011
b = 0110
------------
b = 1101   (13 in decimal)


Now b becomes the original a.

Step 3: a = a ^ b

Now a = a ^ b and b = a (original).

a = (a ^ b) ^ a
  = b


Binary:

a = 1011
b = 1101
------------
a = 0110   (6 in decimal)


Now a becomes the original b.

Final Result
a = 6
b = 13


The values are successfully swapped without using a temporary variable.
*/