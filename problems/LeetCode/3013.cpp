#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Divide an Array Into Subarrays With Minimum Cost II
     * 
     * We need to select k elements: nums[0] (fixed) + (k-1) elements from indices [1, n-1]
     * where the selected elements must be within distance 'dist' from each other.
     * 
     * Strategy: Use sliding window to find the minimum sum of k-1 smallest elements
     * in each valid window, using two multisets for efficient maintenance.
     */
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // Two multisets to maintain k-1 smallest elements efficiently
        multiset<int> smallestElements;  // Contains the k-1 smallest elements in current window
        multiset<int> remainingElements; // Contains the rest of the elements
        
        long long sumOfSmallest = 0;     // Sum of elements in smallestElements
        long long minCost = LLONG_MAX;   // Track minimum cost found so far
        
        // Function to add an element to our data structure
        auto addElement = [&](int value) {
            if (smallestElements.size() < k - 1) {
                // Still need more elements for the k-1 smallest
                smallestElements.insert(value);
                sumOfSmallest += value;
            } else {
                // Check if this element should be in the k-1 smallest
                int largestInSmall = *smallestElements.rbegin();
                
                if (value < largestInSmall) {
                    // Replace the largest element in smallestElements
                    sumOfSmallest += value - largestInSmall;
                    remainingElements.insert(largestInSmall);
                    smallestElements.erase(smallestElements.find(largestInSmall));
                    smallestElements.insert(value);
                } else {
                    // This element goes to remainingElements
                    remainingElements.insert(value);
                }
            }
        };
        
        // Function to remove an element from our data structure
        auto removeElement = [&](int value) {
            auto it = smallestElements.find(value);
            if (it != smallestElements.end()) {
                // Element is in smallestElements - remove it
                sumOfSmallest -= value;
                smallestElements.erase(it);
                
                // If possible, move smallest from remainingElements to smallestElements
                if (!remainingElements.empty()) {
                    int smallest = *remainingElements.begin();
                    sumOfSmallest += smallest;
                    smallestElements.insert(smallest);
                    remainingElements.erase(remainingElements.begin());
                }
            } else {
                // Element is in remainingElements - just remove it
                remainingElements.erase(remainingElements.find(value));
            }
        };
        
        // Initialize: Add first window [1, dist+1] to our data structure
        for (int i = 1; i <= min(dist + 1, (int)nums.size() - 1); i++) {
            addElement(nums[i]);
        }
        
        // Calculate initial cost if we have enough elements
        if (smallestElements.size() == k - 1) {
            minCost = sumOfSmallest;
        }
        
        // Sliding window: Move the window and update the minimum cost
        for (int left = 1, right = dist + 1; right + 1 < nums.size(); left++, right++) {
            // Remove the leftmost element and add the new rightmost element
            removeElement(nums[left]);
            addElement(nums[right + 1]);
            
            // Update minimum cost if we have exactly k-1 elements
            if (smallestElements.size() == k - 1) {
                minCost = min(minCost, sumOfSmallest);
            }
        }
        
        // Return total cost: nums[0] (fixed) + minimum sum of k-1 elements
        return nums[0] + minCost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol;
    
    return 0;
}