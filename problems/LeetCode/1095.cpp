#include <bits/stdc++.h>
using namespace std;

class MountainArray {
public:
    int get(int index){

    }

    int length(){

    }
};

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &arr) {
        int n = arr.length();
        
        int l = 1;
        int r = n - 2;
        int peak_ind = 0;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int mid_val = arr.get(mid);
            if(mid_val > arr.get(mid - 1) && mid_val > arr.get(mid + 1)){
                peak_ind = mid;
                break;
            }
            else if(mid_val < arr.get(mid - 1)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        l = 0;
        r = peak_ind;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int mid_val = arr.get(mid);

            if(mid_val == t) return mid;
            else if(mid_val > t) r = mid - 1;
            else l = mid + 1;
        }

        l = peak_ind + 1;
        r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int mid_val = arr.get(mid);

            if(mid_val == t) return mid;
            else if(mid_val > t) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
       
    Solution sol;
    return 0;
}
