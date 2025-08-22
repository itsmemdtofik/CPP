/**
* !Detect and Remove Loop in Linked List
* Given the head of a linked list that may contain a loop.
* A loop means that the last node of the linked list is connected back to a node in the same list.
* The task is to remove the loop from the linked list (if it exists).
*
* ! Approach: Using Floyd's Cycle Detection Algorithm(two-pointer = slow, fast) - O(n) Time and O(1) Space
*/

#include <iostream>
using namespace std;

/* ------------------ Node Definition ------------------ */
struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};

/* ------------------ Utility to Print Linked List ------------------ */
void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

/* ------------------ Detect and Remove Loop: Approach I ------------------ */
void detectAndRemoveLoop(Node *head) {
    if (head == nullptr || head->next == nullptr) return;

    Node *slow = head;
    Node *fast = head;
    bool loopExists = false;

    /* Step 1: Detect loop using Floyd's cycle detection */
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    /* Step 2: Remove loop if it exists */
    if (loopExists) {
        /* Case 1: Loop starts at head */
        if (slow == head) {
            while (fast->next != head) {
                fast = fast->next;
            }
        } else {
            /* Case 2: Loop starts in middle */
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = nullptr; /* Break the loop */
    }
}

/* ------------------ Detect and Remove Loop: Approach II ------------------ */
void detectAndRemoveLoopII(Node *head) {
    Node *slow = head;
    Node *fast = head;

    /* Detect loop */
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    /* No loop */
    if (slow != fast) return;

    /* Find loop start */
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr; /* Break the loop */
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    /* Create a loop: 4 -> 3 */
    head->next->next->next = head->next;

    cout << "Original List with Loop (partial print to avoid infinite loop):" << endl;
    Node *temp = head;
    for (int i = 0; i < 5; i++) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "..." << endl;


    detectAndRemoveLoop(head);

    cout << "\nList after removing loop:" << endl;
    printList(head);

    return 0;
}
