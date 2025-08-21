/**
 * !Delete last occurrence of an item from linked list
 * Given a singly linked list and a key, the task is to delete the last occurrence of that key in the linked list.
 *
 * Input: head: 1 -> 2 -> 3 -> 1 -> 4 -> NULL, key = 1
 * Output: 1 -> 2 -> 3 -> 4 -> NULL
 *
 * Input: head: 1 -> 2 -> 3 -> 4 -> 5 -> NULL , key = 3
 * Output: 1 -> 2 -> 4 -> 5 -> NULL
 *
 * !Approach: Approach Using Position Tracking (Traversing Twice)
 * Traverse the list to find the position of the last occurrence of the key.
 * Traverse the list again to delete the node at that position.
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
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node *current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr)
            cout << " -> ";
        else
            cout << " -> None\n";
        current = current->next;
    }
}


Node *deleteLastOccurrenceFromSLL(Node *head, int key) {
    if (head == nullptr) {
        return nullptr;
    }

    int lastPosition = -1;
    int currentPosition = 0;
    Node *currentNode = head;

    /* First Pass: Find last occurrence position */
    while (currentNode != nullptr) {
        if (currentNode->data == key) {
            lastPosition = currentPosition;
        }
        currentNode = currentNode->next;
        currentPosition++;
    }

    if (lastPosition == -1) {
        return head; /* Key not found */
    }

    if (lastPosition == 0) {
        Node *temp = head;
        head = head->next; /* Delete head */
        delete temp;
        return head;
    }

    /* Second Pass: Delete node at last position */
    currentNode = head;
    for (int i = 0; i < lastPosition - 1; i++) {
        currentNode = currentNode->next;
    }

    if (currentNode->next != nullptr) {
        Node *temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete temp;
    }

    return head;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(4);

    constexpr int key = 1;
    cout << "Original List:" << endl;
    printSLL(head);

    head = deleteLastOccurrenceFromSLL(head, key);

    cout << "\nAfter deleting last occurrence of " << key << ":" << endl;
    printSLL(head);

    return 0;
}
