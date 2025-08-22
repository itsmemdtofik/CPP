/**
* !Detect and Remove Loop in Linked List
* Given the head of a linked list that may contain a loop.
* A loop means that the last node of the linked list is connected back to a node in the same list.
* The task is to remove the loop from the linked list (if it exists).
*
* ! Approach: Detect and Remove Loop using Hashing - O(n) Time and O(n) Space
*/

#include <iostream>
#include <unordered_set>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};


void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

/* ------------------ Detect and Remove Loop Using Hashing ------------------ */
void detectAndRemoveLoopUsingHashing(Node *head) {
    unordered_set<Node *> seen; /* Stores visited nodes */
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr) {
        /* If node is already seen, break the loop */
        if (seen.find(current) != seen.end()) {
            prev->next = nullptr;
            return;
        }

        seen.insert(current); /* Mark node as visited */
        prev = current;
        current = current->next;
    }
}

/* ------------------ Detect and Remove Loop Using Hashing: Alternate ------------------ */
void detectAndRemoveLoopUsingHashingII(Node *head) {
    unordered_set<Node *> seen;
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (seen.find(current) != seen.end()) {
            /* Case 1: Loop starts at middle node */
            if (prev != nullptr) {
                prev->next = nullptr;
            } else {
                /* Case 2: Loop starts at head (entire list is a cycle) */
                Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = nullptr;
            }
            return;
        } else {
            seen.insert(current);
            prev = current;
            current = current->next;
        }
    }
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


    detectAndRemoveLoopUsingHashing(head);

    cout << "\nList after removing loop:" << endl;
    printList(head);

    return 0;
}
