/*
* <pre>
* !Rotate a Singly Linked List
* Given a singly linked list and an integer k, the task is to rotate the linked list to the left by k places.
*
* @param Examples:
* Input: 10 -> 20 -> 30 -> 40 -> 50, K = 2
* Output: 30 → 40 → 50 → 10 → 20
*
* Input: linked list = 10 -> 20 -> 30 -> 40, k = 6
* Output: 30 -> 40 -> 10 -> 20
*
* !Approach: By changing pointer of kth node - O(n) Time and O(1) Space
* The idea is to first convert the linked list to circular linked list by updating
* the next pointer of last node to the head of linked list.
* Then, traverse to the kth node and update the head of the linked list to the (k+1)th node.
* Finally, break the loop by updating the next pointer of kth node to NULL..
* </pre>
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


Node *rotateSingleLinkedList(Node *head, int k) {
    if (head == nullptr || k == 0)
        return head;

    /* Find the length and last node */
    Node *currentNode = head;
    int length = 1;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
        length++;
    }

    /* Connect last node to head to make it circular */
    currentNode->next = head;

    /* Handle k > length */
    k = k % length;
    if (k == 0) {
        currentNode->next = nullptr; /* Break the circle */
        return head;
    }

    /* Traverse to new tail: (length - k - 1) steps */
    currentNode = head;
    for (int i = 0; i < length - k - 1; i++)
        currentNode = currentNode->next;

    /* Set new head and break the circle */
    Node *newHead = currentNode->next;
    currentNode->next = nullptr;

    return newHead;
}

void printSLL(Node *head) {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->data << " -> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}


int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = rotateSingleLinkedList(head, 6);

    printSLL(head);

    return 0;
}
