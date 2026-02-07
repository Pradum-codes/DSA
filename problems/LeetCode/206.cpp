#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertAtTail(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) return newNode;
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        return head;
    }
    // OPTIMAL Using Recursion
    // ListNode* reverseList(ListNode* head) {
    //     // Base case: if list is empty or has only one node
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }

    //     // Recursively reverse the rest of the list
    //     ListNode* newHead = reverseList(head->next);

    //     // Reverse the current node
    //     head->next->next = head;
    //     head->next = nullptr;

    //     return newHead;
    // }


    // OPTIMAL (IN-PLACE)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* newHead = nullptr;
    //     ListNode* temp = head;

    //     while(temp!= nullptr){
    //         ListNode* newNode = new ListNode(temp->val);
    //         if(newHead == nullptr){
    //             newHead = newNode;
    //         } else {
    //             newNode->next = newHead;
    //             newHead = newNode;
    //         }
    //         temp = temp->next;
    //     }

    //     return newHead;
    // }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    ListNode* head = nullptr;

    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ele; 
        cin >> ele;
        head = sol.insertAtTail(head, ele);
    }

    ListNode* res = nullptr;
    ListNode* temp = sol.reverseList(head);
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}
