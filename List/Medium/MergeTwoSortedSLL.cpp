/**
Merge two sorted linked lists
Given two sorted linked lists consisting of n and m nodes respectively.
The task is to merge both of the lists and return the head of the merged list.

!Approach: Using Iterative Merge - O(n+m) Time and O(1) Space
*/
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};


void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* ------------------ Merge Two Sorted Linked Lists ------------------ */
Node *mergeTwoSortedLists(Node *head1, Node *head2) {
    Node dummy(0); /* Dummy node to simplify merging */
    Node *current = &dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    /* Attach remaining nodes */
    current->next = (head1 != nullptr) ? head1 : head2;

    return dummy.next; /* Return head of merged list */
}


int main() {
    Node *l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);


    Node *l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    Node *merged_head = mergeTwoSortedLists(l1, l2);

    cout << "Merged List:" << endl;
    printList(merged_head);

    return 0;
}
