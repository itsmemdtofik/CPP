#include <iostream>
using namespace std;

/*
 * Node for Circular Linked List
 */
class Node {
public:
    int data;
    Node *next;

    explicit Node(const int data) {
        this->data = data;
        this->next = nullptr;
    }
};

/*
 * Print Circular Linked List
 */
void printList(const Node *last) {
    if (last == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    const Node *head = last->next;
    const Node *temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "NULL" << endl;
}

/*
 * Delete last node in Circular Linked List
 */
Node *deleteFromEnd(Node *last) {
    if (last == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }

    Node *head = last->next;

    /* Case 1: Only one node in the list */
    if (head == last) {
        delete last;
        return nullptr;
    }

    /* Case 2: Multiple nodes, find second last */
    Node *current = head;
    while (current->next != last) {
        current = current->next;
    }

    /* current is now second last */
    current->next = head;
    delete last;
    last = current;

    return last;
}

/*
 * Main function (Example usage)
 */
int main() {
    Node *first = new Node(2);
    Node *second = new Node(3);
    Node *third = new Node(4);

    first->next = second;
    second->next = third;
    third->next = first;

    Node *last = third;

    cout << "Original list: ";
    printList(last);

    last = deleteFromEnd(last);

    cout << "List after deleting last node: ";
    printList(last);

    last = deleteFromEnd(last);
    cout << "List after deleting last node again: ";
    printList(last);

    last = deleteFromEnd(last);
    cout << "List after deleting last node again: ";
    printList(last);

    last = deleteFromEnd(last);
    cout << "List after deleting last node again: ";
    printList(last);

    return 0;
}
