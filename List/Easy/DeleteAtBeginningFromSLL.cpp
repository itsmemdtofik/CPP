/*
Deletion at beginning (Removal of first node) in a Linked List

Given a linked list, The task is to remove the first node from the given linked list.

Examples:

Input : head : 3 -> 12 -> 15 -> 18 -> NULL
Output : 12 -> 15 -> 18 -> NULL

Input : head : 2 -> 4 -> 6 -> 8 -> 33 -> 67 -> NULL
Output : 4 -> 6 -> 8 -> 33 -> 67 -> NULL

 */

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;

    explicit Node(const int val) {
        data = val;
        next = nullptr;
    }
};


Node *deleteAtBeginningInLinkedList(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    const Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}


void printSLL(const Node *head) {
    const Node *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    auto head = new Node(3);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(18);

    cout << "Original list: ";
    printSLL(head);

    head = deleteAtBeginningInLinkedList(head);

    cout << "After deleting first node: ";
    printSLL(head);

    return 0;
}
