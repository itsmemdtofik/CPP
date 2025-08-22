/**
Merge Sort for Linked Lists:

Given a singly linked list, The task is to sort the linked list in non-decreasing order using merge sort.

Examples:

Input: 40 -> 20 -> 60 -> 10 -> 50 -> 30 -> NULL
Output: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

Input: 9 -> 5 -> 2 -> 8 -> NULL
Output: 2 -> 5 -> 8 -> 9 -> NULL

Approach: Using Merge Sort Time Complexity: O(n * log n) and Space: O(n)
*/

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
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


Node *getMiddle(Node *head) {
    if (!head || !head->next) return head;

    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node *merge(Node *left, Node *right) {
    Node dummy(0);
    Node *current = &dummy;

    while (left && right) {
        if (left->data <= right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left) current->next = left;
    if (right) current->next = right;

    return dummy.next;
}


Node *mergeSortSingleLinkedList(Node *head) {
    if (!head || !head->next) return head;


    Node *mid = getMiddle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr; /* Break the link */

    /* Recursively sort both halves */
    left = mergeSortSingleLinkedList(left);
    right = mergeSortSingleLinkedList(right);

    /* Merge the sorted halves */
    return merge(left, right);
}


Node *createSingleLinkedList(const int arr[], int n) {
    if (n == 0) return nullptr;

    Node *head = new Node(arr[0]);
    Node *current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}


int main() {
    int arr[] = {40, 20, 60, 10, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = createSingleLinkedList(arr, n);

    cout << "Original list:" << endl;
    printSLL(head);

    head = mergeSortSingleLinkedList(head);

    cout << "Sorted list:" << endl;
    printSLL(head);

    return 0;
}
