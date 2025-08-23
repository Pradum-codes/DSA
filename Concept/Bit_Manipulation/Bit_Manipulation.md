## Finding a Superset of a given set
```
set -> 1 2 3

total = 2^n = 8

1 2 3
i i i <- value going from 0 to n-1
0 0 0 -> 0 <- mask for i = 0 to n-1 => (1 << i) gives 001 and putting '&' operator with mask 1&0 gives 0 till n-1 so first subset is empty.
0 0 1 -> 1 <- mask (i = 0) => (1<<i) => 001 & 001 subset=> {1}, (i=1) => (1<<i) => 010 & 001 subset=> {1}, (i=2) => (1<<i) => 100 & 001 subset=> {1}
0 1 0 -> 2 <- mask (i = 0) => (1<<i) => 001 & 010 subset=> {}, (i=1) => (1<<i) => 010 & 010 subset=> {2}
0 1 1 -> 3 <- mask
1 0 0 -> 4 <- mask
1 0 1 -> 5 <- mask
1 1 0 -> 6 <- mask
1 1 1 -> 7 <- mask
Consider the set: {1, 2, 3}

Total number of subsets = 2^n = 2^3 = 8

We can represent each subset using a binary mask of length n (here, n = 3).
Each bit in the mask determines whether the corresponding element is included in the subset.

Index mapping:
Bit position (from right) -> Element
i = 0 -> 1
i = 1 -> 2
i = 2 -> 3

--------------------------------------------
Mask | Binary | Subset formed
--------------------------------------------
0    | 000    | {}       -> no bits set
1    | 001    | {1}      -> only i=0 bit set
2    | 010    | {2}      -> only i=1 bit set
3    | 011    | {1,2}    -> bits i=0, i=1 set
4    | 100    | {3}      -> only i=2 bit set
5    | 101    | {1,3}    -> bits i=0, i=2 set
6    | 110    | {2,3}    -> bits i=1, i=2 set
7    | 111    | {1,2,3}  -> all bits set
--------------------------------------------

Explanation of how to check each element:
--------------------------------------------
For each subset (mask from 0 to 2^n - 1):
    For each element index i (0 to n-1):
        If (mask & (1 << i)) != 0
            -> include nums[i] in the subset

Example: mask = 5 (binary 101)
    Check bits:
        i=0: (101 & 001) = 1 -> include nums[0] = 1
        i=1: (101 & 010) = 0 -> exclude nums[1] = 2
        i=2: (101 & 100) = 4 -> include nums[2] = 3
    Subset = {1,3}
```

#### SOLVE:
##### Leetcode: [78](https://leetcode.com/problems/subsets/description/), [2044](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/),


## Swapping of two Number
[Chek this out](../Bit_Manipulation/Swap.cpp)

## Setting i'th Bit
```
What if we want to set a bit in a number like the question says set the 2nd bit of 11.
We have 11 in Binary as 1011 and we want to set the 2nd bit from the right and make it 1111 i.e., 15

what we can do is doing an OR operation after left shifting the 1 to the i'th
In our Example 1<<2 give us 0100
After this we can do OR operation with the orignal Number
    1011  -> 11
OR  0100  -> 4
--------
    1111  -> 15
```

[CHek this out](../Bit_Manipulation/SetBit.cpp)

### Same as Setting we can also clear a bit
```
n&~(i<<1)
```
### Toggling the bit
```
n^(1<<i)
```

## Checking if the Number is a power of '2'
```
A number is a power of 2 if and only if it has exactly one set bit (1) in its binary representation.

POWER   VALUE   BINARY
0       1       0001
1       2       0010
2       4       0100
3       8       1000

We can leverage the property of bitwise AND (&) to check this efficiently:

If n is a power of 2, then
n & (n−1)=0
This works because subtracting 1 from n flips all bits from the rightmost set bit (including itself).
Thus, performing n & (n-1) clears the only set bit if n is a power of 2, leaving 0.

n      = 10110 (22)
n - 1  = 10101 (21)
-----------------
n&(n-1)= 10100 (20) ≠ 0

so 10110 -> 10100

like this we only just need to find the only bit and set it to 0 if the result is 0 then the number is a power of 2.

    1000 -> 8
AND 0111 -> 7
    ---------
    0000 -> 0

```
[Check This Out](../Bit_Manipulation/PowerOfTwo.cpp)


## Check if the number is Even or Odd
```
In binary, the least significant bit (LSB) determines whether a number is even or odd:

-> If the LSB is 0, the number is even.
-> If the LSB is 1, the number is odd.

We can use a simple bitwise AND operation:

n & 1

-> If the result is 0, the number is even.
-> If the result is 1, the number is odd.

n      = 10110 (22)
1      = 00001
----------------
n & 1  = 00000 = 0  → Even


n      = 1101 (13)
1      = 0001
----------------
n & 1  = 0001 = 1  → Odd

```
[Check This out](../Bit_Manipulation/EvenOdd.cpp)

## Brian Kernighan’s Algorithm

```
Brian Kernighan's algorithm is an efficient method for counting the number of "set bits" (bits with a value of 1) in the binary representation of an integer.

Algorithm Logic: The core of the algorithm relies on a specific bitwise operation: n & (n - 1).
Bitwise AND with n-1:
When a number n is bitwise ANDed with n-1, the rightmost set bit in n is effectively unset (changed from 1 to 0), and all bits to its right are also affected (inverted).
Iterative Unsetting:
The algorithm repeatedly applies this n = n & (n - 1) operation within a loop. In each iteration, one set bit is cleared.
Counting Iterations:
A counter is incremented in each iteration. The loop continues until n becomes 0, indicating that all set bits have been cleared. The final value of the counter represents the total number of set bits in the original integer.
```
[Check This Out](../../LeetCode/461.cpp)
[Check This Out](../../LeetCode/2220.cpp)
