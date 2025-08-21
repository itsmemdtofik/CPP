/*
Remove every k-th node of the linked list
Given a singly linked list, the task is to remove every kth node of the linked list. Assume that k is always less than or equal to the length of the Linked List.

Examples :

Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6, k = 2
Output: 1 -> 3 -> 5
Explanation: After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 .

Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation: After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.
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


Node *deleteKthNodeFromSLL(Node *head, int k) {
    if (head == nullptr || k <= 0)
        return head;

    Node *currentNode = head;
    Node *previousNode = nullptr;
    int count = 0;

    while (currentNode != nullptr) {
        count++;

        /* If count is multiple of k, remove current node */
        if (count % k == 0) {
            if (previousNode != nullptr) {
                previousNode->next = currentNode->next;
            } else {
                /* If removing the head node */
                head = currentNode->next;
            }
            /* Move currentNode forward */
            Node *temp = currentNode;
            currentNode = currentNode->next;
            delete temp; /* Free memory */
        } else {
            /* Update previousNode only if currentNode is not deleted */
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    return head;
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

    int k = 2;
    head = deleteKthNodeFromSLL(head, k);

    printSLL(head);

    return 0;
}
