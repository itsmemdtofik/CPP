/**

* <pre>
* !Remove Duplicates from Un-Sorted List
* Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
* leaving only distinct numbers from the original list. Return the linked list sorted as well.
*
* Input: head = [1 -> 2 -> 5 -> 6 -> 5 -> 2 -> null]
* Output: [1 -> 2 -> 5 -> 6 -> null]
*
* !Approach: Using Hashing Time Complexity: O(n) Space Complexity: O(n)
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers.
* </pre>
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


void printSLL(Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

/* ------------------ Remove Duplicates from Unsorted Linked List ------------------ */
Node *removeDuplicatesFromUnsortedSLL(Node *head) {
    if (!head || !head->next) return head;

    unordered_set<int> seen;
    Node *current = head;
    seen.insert(current->data);

    while (current->next) {
        if (seen.count(current->next->data)) {
            /* Skip the duplicate node */
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp; /* free memory */
        } else {
            seen.insert(current->next->data);
            current = current->next;
        }
    }
    return head;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);

    cout << "Before Removing Duplicates:" << endl;
    printSLL(head);

    head = removeDuplicatesFromUnsortedSLL(head);

    cout << "After Removing Duplicates:" << endl;
    printSLL(head);

    return 0;
}
