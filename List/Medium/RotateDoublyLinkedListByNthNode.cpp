/**
Rotate Doubly linked list by N nodes
Given a doubly-linked list, the task is to rotate the linked list counter-clockwise by p nodes. Here p is a given positive integer and is smaller than the count of nodes in the linked list.

Examples:

Input: 1 2 3 4 5, p = 2
Output: 3 4 5 1 2
*/

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};


void printDLL(Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " <-> ";
        current = current->next;
    }
    cout << endl;
}

/* Rotate doubly linked list counter-clockwise by 'position' nodes */
Node *rotateDoublyLinkedList(Node *head, int position) {
    if (!head || !head->next || position == 0)
        return head;

    Node *current = head;
    int length = 1;

    /* Step 1: Find last node and length */
    while (current->next) {
        current = current->next;
        length++;
    }
    Node *tail = current;

    /* Step 2: Make the list circular */
    tail->next = head;
    head->prev = tail;

    /* Step 3: Move head & tail by 'position' nodes */
    position = position % length; /* handle position > length */
    for (int i = 0; i < position; i++) {
        head = head->next;
        tail = tail->next;
    }

    /* Step 4: Break the circularity */
    tail->next = nullptr;
    head->prev = nullptr;

    return head;
}


int main() {
    Node *head = new Node(2);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original List:" << endl;
    printDLL(head);

    int p = 3;
    head = rotateDoublyLinkedList(head, p);

    cout << "\nList after rotating by " << p << " nodes:" << endl;
    printDLL(head);

    return 0;
}
