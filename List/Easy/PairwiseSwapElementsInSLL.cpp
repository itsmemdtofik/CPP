/*
Pairwise Swap Elements of a given Linked List

Given a singly linked list, the task is to swap linked list elements pairwise.

Examples:

Input : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Output : 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> NULL

Reverse-a-Linked-List-in-groups-of-given-size-1

Input : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Output : 2 -> 1 -> 4 -> 3 -> 5 -> NULL
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


void pairwiseSwapInSingleLinkedList(Node *head) {
    Node *currentNode = head;

    while (currentNode != nullptr && currentNode->next != nullptr) {
        /* Swap data of current node and next node */
        const int temp = currentNode->data;
        currentNode->data = currentNode->next->data;
        currentNode->next->data = temp;

        currentNode = currentNode->next->next;
    }
}


void printSLL(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr)
            cout << " -> ";
        current = current->next;
    }
    cout << " -> NULL" << endl;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    pairwiseSwapInSingleLinkedList(head);

    printSLL(head);

    return 0;
}
