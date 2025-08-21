/*
Deletion from a Circular Linked List

In this article, we will learn how to delete a node from a circular linked list.
In a circular linked list, the last node connects back to the first node, creating a loop.

There are three main ways to delete a node from circular linked list:

1. Deletion at the beginning
2. Deletion at specific position
3. Deletion at the end
Now, let’s look at the methods and steps for these three deletion operations.

Deletion from a Circular Linked List:
Deletion involves removing a node from the linked list.
The main difference is that we need to ensure the list remains circular after the deletion.
We can delete a node in a circular linked list in three ways:
*/

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;

    explicit Node(const int data) {
        this->data = data;
        this->next = nullptr;
    }
};


Node *deleteAtSpecificPosition(Node *last, const int key) {
    if (last == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }

    Node *currentNode = last->next; // head
    Node *previousNode = last;

    /* Case 1: only one node, and it matches the key */
    if (currentNode == last && currentNode->data == key) {
        delete currentNode;
        return nullptr;
    }

    /* Case 2: deleting the first node (head) */
    if (currentNode->data == key) {
        last->next = currentNode->next;
        delete currentNode;
        return last;
    }

    /* Case 3: traverse to find node */
    while (currentNode != last && currentNode->data != key) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }


    if (currentNode->data == key) {
        previousNode->next = currentNode->next;
        if (currentNode == last) {
            /* deleting last node */
            last = previousNode;
        }
        delete currentNode;
    } else {
        cout << "Node with data " << key << " not found." << endl;
    }
    return last;
}


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


int main() {
    const auto head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);


    Node *last = head->next->next;
    last->next = head;

    cout << "Original list: ";
    printList(last);

    constexpr int key = 3;
    last = deleteAtSpecificPosition(last, key);

    cout << "List after deleting node " << key << ": ";
    printList(last);


    return 0;
}
