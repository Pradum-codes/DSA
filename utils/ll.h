// mycpplib.h
#pragma once
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// Linked List Node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Create linked list from vector
ListNode* createLL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Print linked list (safe, stops if loop detected)
void printLL(ListNode* head) {
    unordered_set<ListNode*> visited;
    while (head) {
        if (visited.count(head)) {
            cout << "LOOP DETECTED at node " << head->val << "\n";
            return;
        }
        visited.insert(head);
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Insert at head
void insertAtHead(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertAtTail(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
}

// Delete first occurrence of value
void deleteNode(ListNode*& head, int val) {
    if (!head) return;
    if (head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    ListNode* curr = head;
    while (curr->next && curr->next->val != val) curr = curr->next;
    if (curr->next) {
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

// Create a loop in linked list at given position (0-based)
void createLoop(ListNode* head, int pos) {
    if (!head || pos < 0) return;
    ListNode* loopNode = nullptr;
    ListNode* curr = head;
    int idx = 0;
    while (curr->next) {
        if (idx == pos) loopNode = curr;
        curr = curr->next;
        idx++;
    }
    if (loopNode) curr->next = loopNode;  // last node points to loopNode
}

// Detect loop using Floyd's cycle detection
bool detectLoop(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
