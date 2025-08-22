/**
Merge Sort for Doubly Linked List
Given a doubly linked list, The task is to sort the doubly linked list in non-decreasing order using merge sort.

Examples:

Input: 10 <-> 8 <-> 4 <-> 2
Output: 2 <-> 4 <-> 8 <-> 10

Input: 5 <-> 3 <-> 2
Output: 2 <-> 3 <-> 5

Approach: Using Merge Sort Time Complexity: O(n Log n)  Space: O(1)
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

/* Merge two sorted doubly linked lists */
Node *merge(Node *left, Node *right) {
    Node dummy(0);
    Node *current = &dummy;

    while (left && right) {
        if (left->data <= right->data) {
            current->next = left;
            left->prev = current;
            left = left->next;
        } else {
            current->next = right;
            right->prev = current;
            right = right->next;
        }
        current = current->next;
    }

    /* Attach remaining nodes */
    if (left) current->next = left;
    if (right) current->next = right;

    if (current->next) current->next->prev = current;

    Node *head = dummy.next;
    if (head) head->prev = nullptr; /* Detach dummy */
    return head;
}

/* Merge Sort for Doubly Linked List */
Node *mergeSortDoublyLinkedList(Node *head) {
    if (!head || !head->next) return head;

    /* Split the list into two halves */
    Node *mid = getMiddle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr;
    if (right) right->prev = nullptr;

    /* Recursively sort both halves */
    left = mergeSortDoublyLinkedList(left);
    right = mergeSortDoublyLinkedList(right);

    /* Merge the sorted halves */
    return merge(left, right);
}

/* Helper function to create doubly linked list from array */
Node *createDoublyLinkedList(const int arr[], int n) {
    if (n == 0) return nullptr;
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < n; i++) {
        Node *newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}


int main() {
    int arr[] = {4, 2, 1, 3, -100, 1, 200, 10, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = createDoublyLinkedList(arr, n);

    cout << "Original list:" << endl;
    printDLL(head);

    head = mergeSortDoublyLinkedList(head);

    cout << "Sorted list:" << endl;
    printDLL(head);

    return 0;
}
