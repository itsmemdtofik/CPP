/*
Merge Sort for Linked Lists:

Given a singly linked list, the task is to sort the linked list in non-decreasing order using merge sort.

Examples:

Input: 40 -> 20 -> 60 -> 10 -> 50 -> 30 -> NULL
Output: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

Input: 9 -> 5 -> 2 -> 8 -> NULL
Output: 2 -> 5 -> 8 -> 9 -> NULL

Approach: Using Merge Sort
Time Complexity: O(n * log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
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


Node *mergeSort(Node *head) {
    if (!head || !head->next) return head; // Base case

    /* Split list into two halves */
    Node *mid = getMiddle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr; /* Break the link */

    /* Recursively sort both halves */
    left = mergeSort(left);
    right = mergeSort(right);

    /* Merge the sorted halves */
    return merge(left, right);
}

/* Helper function to create linked list from vector */
Node *createSingleLinkedList(const vector<int> &nums) {
    if (nums.empty()) return nullptr;

    Node *head = new Node(nums[0]);
    Node *current = head;

    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new Node(nums[i]);
        current = current->next;
    }

    return head;
}


int main() {
    vector<int> nums = {4, 2, 1, 3, -100, 1, 200, 10, 100};
    Node *head = createSingleLinkedList(nums);

    cout << "Before Sorting the list:" << endl;
    printSLL(head);

    head = mergeSort(head);

    cout << "After Sorting the list:" << endl;
    printSLL(head);

    return 0;
}
