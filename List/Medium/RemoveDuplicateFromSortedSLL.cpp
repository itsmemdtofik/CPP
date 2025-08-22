/**
* <pre>
* !Remove Duplicates from Sorted List II
* Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
* Return the linked list sorted as well.
*
* Input: head = [1,2,3,3,4,4,5]
* Output: [1, 2, 3, 4, 5]
*
* !Approach: Iterative Time Complexity: O(n) Space Complexity: O(1)
*
* </pre>
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
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

/* ------------------ Remove Duplicates from Sorted Singly Linked List ------------------ */
Node *removeDuplicatesFromSortedSLL(Node *head) {
    /* Edge case: empty list or only one node */
    if (head == nullptr || head->next == nullptr) return head;

    Node *current = head;

    /* Traverse the list */
    while (current != nullptr && current->next != nullptr) {
        /* If current node and next node have the same value, skip the next node */
        if (current->data == current->next->data) {
            Node *temp = current->next; /* store duplicate node */
            current->next = current->next->next; /* remove duplicate */
            delete temp; /* free memory */
        } else {
            /* Move to next node if no duplicate */
            current = current->next;
        }
    }

    return head;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(5);

    cout << "Before Removing Duplicates:" << endl;
    printSLL(head);

    head = removeDuplicatesFromSortedSLL(head);

    cout << "After Removing Duplicates:" << endl;
    printSLL(head);

    return 0;
}
