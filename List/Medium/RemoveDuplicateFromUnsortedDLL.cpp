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
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " <-> ";
        current = current->next;
    }
    cout << endl;
}

/* ------------------ Remove Duplicates ------------------ */
Node *removeDuplicates(Node *head) {
    if (!head || !head->next) return head;

    unordered_set<int> seen;
    Node *current = head;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            /* Duplicate found, remove current node */
            Node *temp = current;
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            current = current->next;
            delete temp; /* free memory */
        } else {
            seen.insert(current->data);
            current = current->next;
        }
    }

    return head;
}

/* ------------------ Helper to Create Doubly Linked List ------------------ */
Node *createDoublyLinkedList(const vector<int> &values) {
    if (values.empty()) return nullptr;

    Node *head = new Node(values[0]);
    Node *current = head;
    for (size_t i = 1; i < values.size(); i++) {
        Node *newNode = new Node(values[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}


int main() {
    vector<vector<int> > testLists = {
        {1, 2, 3, 2, 4},
        {1, 1, 1, 1},
        {1, 2, 3, 4}
    };

    for (size_t i = 0; i < testLists.size(); i++) {
        cout << "\nOriginal List " << i + 1 << ":" << endl;
        Node *head = createDoublyLinkedList(testLists[i]);
        printDLL(head);

        head = removeDuplicates(head);
        cout << "List after removing duplicates:" << endl;
        printDLL(head);
    }

    return 0;
}
