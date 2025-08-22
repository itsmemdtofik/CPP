/**
Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};


void printSLL(Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

/* ------------------ Reverse Entire Linked List ------------------ */
Node *reverse(Node *head) {
    Node *previousNode = nullptr;
    Node *currentNode = head;

    while (currentNode) {
        Node *nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    return previousNode;
}

/* ------------------ Reverse Nodes in k-Group ------------------ */
Node *reverseKGroup(Node *head, int k) {
    if (!head || k <= 1) return head;

    /* Dummy node simplifies head handling */
    Node dummy(0);
    dummy.next = head;
    Node *previousNode = &dummy;

    while (head) {
        Node *currentNode = head;
        int count = 1;

        /* Check if at least k nodes remain */
        while (count < k && currentNode->next) {
            currentNode = currentNode->next;
            count++;
        }

        if (count < k) break; /* Less than k nodes, no reversal */

        Node *nextGroup = currentNode->next; /* Store next group's head */
        currentNode->next = nullptr; // Cut current k-group

        Node *reversedHead = reverse(head); /* Reverse current k-group */
        previousNode->next = reversedHead; /* Connect previous group to reversed */

        head->next = nextGroup; /* Connect tail to next group */
        previousNode = head; /* Move previous pointer */
        head = nextGroup; /* Move head forward */
    }

    return dummy.next;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list:" << endl;
    printSLL(head);

    int k = 2;
    Node *new_head = reverseKGroup(head, k);

    cout << "\nReversed in k-group (k=" << k << "):" << endl;
    printSLL(new_head);

    return 0;
}
