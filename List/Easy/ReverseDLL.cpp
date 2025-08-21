/*
Given a Doubly Linked List, the task is to reverse the Doubly Linked List.

Examples:

Input: Doubly Linked List = 1 <-> 2 <-> 3 -> NULL
Output: Reversed Doubly Linked List = 3 <-> 2 <-> 1 -> NULL

Input: Doubly Linked List = 1 ->NULL
Output: Reversed Doubly Linked List = 1 ->NULL

Approach: Using Two Pointers - O(n) Time and O(1) Space
 */

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};


Node *reverseDoublyLinkedList(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *currentNode = head;
    Node *temp = nullptr;

    while (currentNode != nullptr) {
        /* Swap next and prev */
        temp = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = temp;

        /* Move to next node in original list */
        head = currentNode; /* Update head to current node */
        currentNode = currentNode->prev; /* Because prev and next are swapped */
    }

    return head;
}


void printDLL(Node *head) {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        cout << " " << currentNode->data << " ->";
        currentNode = currentNode->next;
    }
    cout << " NULL" << endl;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original Doubly Linked List" << endl;
    printDLL(head);

    head = reverseDoublyLinkedList(head);

    cout << "Reversed Doubly Linked List" << endl;
    printDLL(head);

    return 0;
}
