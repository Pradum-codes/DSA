#include <bits/stdc++.h>
#include "../utils/ll.h"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;
    }
};

// Better
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* tempA = headA;
//         unordered_set<ListNode*> s;
//         while(tempA){
//             s.insert(tempA);
//             tempA = tempA->next;
//         }
        
//         ListNode* tempB = headB;
//         while(tempB) {
//             if(s.find(tempB) != s.end()) return tempB;
//             tempB = tempB->next;
//         }
        
//         return nullptr;
//     }
// };

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* tempA = headA;
//         while(tempA){
//             ListNode* tempB = headB;
//             while(tempB){
//                 if(tempA == tempB) return tempA;
//                 tempB = tempB->next;
//             }
//             tempA = tempA->next;
//         }

//         return nullptr;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr1 = {4, 1};
    vector<int> arr2 = {5, 6, 1};
    vector<int> intersection = {8, 4, 5};

    ListNode* headA = createLL(arr1);
    ListNode* headB = createLL(arr2);
    ListNode* headInter = createLL(intersection);

    // Find tail of list A
    ListNode* tempA = headA;
    while (tempA->next) {
        tempA = tempA->next;
    }
    // Link intersection
    tempA->next = headInter;

    // Find tail of list B
    ListNode* tempB = headB;
    while (tempB->next) {
        tempB = tempB->next;
    }
    tempB->next = headInter;

    cout << "List A: ";
    printLL(headA);
    cout << "List B: ";
    printLL(headB);

    Solution sol;
    ListNode* head =  sol.getIntersectionNode(headA, headB);
    cout << head->val << endl;

    return 0;
}
