/**
* <pre>
* !Intersection of two Sorted Linked Lists
* Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists.
* The new list should be made with its own memory — the original lists should not be changed.
* Input:
* First linked list: 1->2->3->4->6
* Second linked list be 2->4->6->8,
* Output: 2->4->6.
* The elements 2, 4, 6 are common in
* both the list so they appear in the
* intersection list.
*
* !Approach:  Two Pointer Switching Technique Time: O(n) Space: O(1)
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


void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* ------------------ Intersection of Two Sorted Lists ------------------ */
Node *getIntersection(Node *head1, Node *head2) {
    Node dummy(0); /* Dummy node to simplify list creation */
    Node *current = &dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data == head2->data) {
            current->next = new Node(head1->data); /* Create new node for intersection */
            current = current->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }

    return dummy.next; /* Return head of new intersection list */
}


int main() {
    /* List 1: 1 -> 2 -> 3 -> 4 -> 6 */
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    /* List 2: 2 -> 4 -> 6 -> 8 */
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    cout << "First List:" << endl;
    printList(head1);

    cout << "Second List:" << endl;
    printList(head2);

    Node *intersection = getIntersection(head1, head2);

    cout << "Intersection of the two lists:" << endl;
    printList(intersection);

    return 0;
}
