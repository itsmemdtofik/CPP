/**
* <pre>
* !Remove duplicates from an unsorted doubly linked list
* Given an unsorted doubly linked list containing n nodes, the task is to remove duplicate nodes while preserving the original order.
*
* Examples:
* Input: Doubly Linked List = 1 <-> 2 <-> 3 <-> 2 <-> 4
* Output: Doubly Linked List = 1 <-> 2 <-> 3 <-> 4
*
* !Approach:Using HashSet - O(n) Time and O(n) Space
* </pre>
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


struct Node {
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {
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

/* ------------------ Remove Duplicates ------------------ */
Node *removeDuplicates(Node *head) {
    if (!head) return nullptr;

    unordered_set<int> seen;
    Node *current = head;

    while (current) {
        if (seen.find(current->data) != seen.end()) {
            Node *prevNode = current->prev;
            Node *nextNode = current->next;

            if (prevNode) prevNode->next = nextNode;
            if (nextNode) nextNode->prev = prevNode;

            if (current == head) head = nextNode; /* head was duplicate */

            Node *temp = current;
            current = current->next;
            delete temp;
        } else {
            seen.insert(current->data);
            current = current->next;
        }
    }

    return head;
}

/* ------------------ Helper to Create Doubly Linked List ------------------ */
Node *createDoublyLinkedList(const vector<int> &nums) {
    Node *dummy = new Node(0);
    Node *current = dummy;

    for (int num: nums) {
        Node *newNode = new Node(num);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    Node *head = dummy->next;
    if (head) head->prev = nullptr; /* detach dummy */
    delete dummy;
    return head;
}


int main() {
    vector<int> values = {1, 2, 3, 2, 4};
    Node *head = createDoublyLinkedList(values);

    cout << "Original List:" << endl;
    printDLL(head);

    head = removeDuplicates(head);
    cout << "List after removing duplicates:" << endl;
    printDLL(head);

    return 0;
}
