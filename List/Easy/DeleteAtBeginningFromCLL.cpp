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

/*
 * Node for Circular Linked List
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
 * Delete node at the beginning of Circular Linked List
 * last → pointer to last node in CLL
 */
Node *deleteAtBeginning(Node *last) {
    if (last == nullptr) {
        cout << "List is empty!" << endl;
        return nullptr;
    }

    Node *head = last->next;


    if (head == last) {
        delete head;
        return nullptr;
    }


    last->next = head->next;
    delete head;

    return last;
}

/*
 * Print Circular Linked List
 */
void printList(Node *last) {
    if (last == nullptr)
        return;

    Node *head = last->next;
    Node *temp = head;

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


    last = deleteAtBeginning(last);

    cout << "List after deleting first node: ";
    printList(last);

    /* Cleanup remaining nodes */
    if (last != nullptr) {
        Node *head = last->next;
        const Node *temp = head;
        do {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }

    return 0;
}
