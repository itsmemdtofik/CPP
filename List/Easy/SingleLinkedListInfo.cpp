#include <iostream>
using namespace std;

// ✅ Node structure
class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

/*
============================
Difference Between Loops
============================

1️⃣ while(current->next != nullptr)
✔️ Stops at the last node
🔧 Use case: when you want to modify the last node (e.g., insert at end, check last node value)

Example:
For list: 10 -> 20 -> 30
Iteration 1: current = 10 -> current->next = 20 -> OK
Iteration 2: current = 20 -> current->next = 30 -> OK
Iteration 3: current = 30 -> current->next = nullptr -> Stop
➡️ current points to 30 ✅

2️⃣ while(current != nullptr)
❌ Stops after passing the last node (current becomes nullptr)
🔧 Use case: when you want to traverse/visit all nodes (print, count, search)
*/

// 🔹 Print the linked list
void printList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        // traverse all nodes
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// 🔹 Insert at end using while(current->next != nullptr)
Node *insertAtEnd(Node *head, int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) // empty list
        return newNode;

    Node *current = head;
    while (current->next != nullptr) // stops at last node
        current = current->next;

    current->next = newNode; // attach new node
    return head;
}

// 🔹 Insert at middle (even/odd length logic)
Node *insertAtMidOfEvenOdd(Node *head, int data) {
    Node *newNode = new Node(data);

    if (!head) // empty list
        return newNode;

    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    // Find middle using slow/fast pointers
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (!fast) {
        // Even-length: insert before second middle
        if (!prev) {
            // Only 2 nodes
            newNode->next = head;
            return newNode;
        }
        prev->next = newNode;
        newNode->next = slow;
    } else {
        // Odd-length: insert after middle
        newNode->next = slow->next;
        slow->next = newNode;
    }

    return head;
}

// 🔹 Count nodes using while(current != nullptr)
int countNodes(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// 🔹 Search for a value
bool searchValue(Node *head, int target) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == target)
            return true;
        current = current->next;
    }
    return false;
}

// 🔹 Example usage
int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);

    head = insertAtEnd(head, 50);
    cout << "After inserting 50 at end: ";
    printList(head);

    head = insertAtMidOfEvenOdd(head, 25);
    cout << "After inserting 25 at middle: ";
    printList(head);

    cout << "Total nodes: " << countNodes(head) << endl;

    int target = 25;
    if (searchValue(head, target))
        cout << "Value " << target << " found in list!" << endl;
    else
        cout << "Value " << target << " not found." << endl;

    return 0;
}
