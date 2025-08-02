#include <bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n; // 2^n subsets
    
    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))  // if the i-th bit is set
                subset.push_back(nums[i]);
                // cout << "mask: " << mask << " i: "<< i << " Mani: " << (1<<i) << endl;
        }
        
        // Print current subset
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    generateSubsets(arr);
    return 0;
}

/*
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
*/