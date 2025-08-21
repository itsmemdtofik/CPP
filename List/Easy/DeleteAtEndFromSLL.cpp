#include <iostream>
using namespace std;

/*
 * Node for Singly Linked List
 */
class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

/*
 * Print Singly Linked List
 */
void printSLL(Node *head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

/*
 * Delete last node in Singly Linked List
 */
Node *deleteAtEnd(Node *head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return nullptr;
    }

    /* Case 1: Only one node */
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    /* Case 2: Multiple nodes */
    Node *prev = nullptr;
    Node *current = head;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;
    delete current;
    return head;
}

/*
 * Main function (Example usage)
 */
int main() {
    Node *head = new Node(3);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(18);

    cout << "Original List:" << endl;
    printSLL(head);


    head = deleteAtEnd(head);
    cout << "\nAfter deleting last node:" << endl;
    printSLL(head);


    head = deleteAtEnd(head);
    cout << "\nAfter deleting last node again:" << endl;
    printSLL(head);


    head = deleteAtEnd(head);
    cout << "\nAfter deleting last node again:" << endl;
    printSLL(head);


    head = deleteAtEnd(head);
    cout << "\nAfter deleting last node again:" << endl;
    printSLL(head);

    return 0;
}
