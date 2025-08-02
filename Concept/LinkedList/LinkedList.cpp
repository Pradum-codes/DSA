#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at head
    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Insert at specific index (0-based)
    void insertAtIndex(int val, int index) {
        if (index < 0) {
            cout << "Invalid index!\n";
            return;
        }
        if (index == 0) {
            insertAtHead(val);
            return;
        }
        ListNode* temp = head;
        for (int i = 0; temp && i < index - 1; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Index out of bounds!\n";
            return;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at head
    void deleteAtHead() {
        if (!head) return;
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at tail
    void deleteAtTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        ListNode* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at specific index
    void deleteAtIndex(int index) {
        if (index < 0 || !head) {
            cout << "Invalid index!\n";
            return;
        }
        if (index == 0) {
            deleteAtHead();
            return;
        }
        ListNode* temp = head;
        for (int i = 0; temp->next && i < index - 1; i++) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Index out of bounds!\n";
            return;
        }
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Search for a value
    bool search(int val) {
        ListNode* temp = head;
        while (temp) {
            if (temp->val == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Get length of list
    int length() {
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display the list
    void display() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtIndex(25, 2);

    cout << "Linked List: ";
    list.display();

    cout << "Length: " << list.length() << endl;

    cout << "Searching for 25: " << (list.search(25) ? "Found" : "Not Found") << endl;

    list.deleteAtIndex(2);
    cout << "After deleting index 2: ";
    list.display();

    list.deleteAtHead();
    cout << "After deleting head: ";
    list.display();

    list.deleteAtTail();
    cout << "After deleting tail: ";
    list.display();

    return 0;
}
