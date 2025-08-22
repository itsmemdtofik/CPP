/**
Convert singly linked list into circular linked list

Given a singly linked list, the task is to convert it into a circular linked list.

Examples:

Input: head: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Explanation: Singly linked list is converted to circular by pointing last node to head.

Input: head: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> NULL
Output: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> NULL
Explanation: Singly linked list is converted to circular by pointing last node to head.
*/

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};

/* ------------------ Recursive Conversion ------------------ */
void recursive(Node *current, Node *head) {
    /* Base case: if current is the last node (next == NULL) */
    if (current->next == nullptr) {
        current->next = head; /* point last node to head */
        return;
    }
    recursive(current->next, head); /* Recur for next node */
}

/* ------------------ Iterative Conversion ------------------ */
void iterative(Node *head) {
    Node *current = head;
    /* Traverse until the last node */
    while (current->next != nullptr) {
        current = current->next;
    }
    /* Point last node to head */
    current->next = head;
}

/* ------------------ Print Circular Linked List ------------------ */
void printCircularList(Node *head) {
    if (head == nullptr) return;

    Node *current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head); /* stop when we reach head again */

    cout << "NULL" << endl; /* just for representation */
}


int main() {
    /* -------- Recursive Approach Example -------- */
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(14);
    head->next->next->next = new Node(16);

    recursive(head, head);
    cout << "Using Recursive Approach:" << endl;
    printCircularList(head);

    /* -------- Iterative Approach Example -------- */
    Node *head1 = new Node(11);
    head1->next = new Node(12);
    head1->next->next = new Node(13);
    head1->next->next->next = new Node(14);

    iterative(head1);
    cout << "Using Iterative Approach:" << endl;
    printCircularList(head1);

    return 0;
}
