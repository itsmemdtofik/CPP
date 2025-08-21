/*
Delete N nodes after M nodes of a linked list

Given a linked list and two integers m and n, the task is to traverse the linked list such that you skip m nodes,
then delete the next n nodes, and continue the same till end of the linked list.

Note: m cannot be 0.

Example:
Input: Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2
Output: 9->1->5->9->10->1
Explanation: Deleting 1 node after skipping 2 nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.

Input: Linked List: 1->2->3->4->5->6, n = 1, m = 6
Output: 1->2->3->4->5->6
Explanation: After skipping 6 nodes for the first time , we will reach of end of the linked list, so, we will get the given linked list itself.

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


Node *skipMDeleteN(Node *head, int m, int n) {
    Node *currentNode = head;

    while (currentNode != nullptr) {
        for (int i = 1; i < m && currentNode != nullptr; i++) {
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr) {
            return head;
        }


        Node *nextNode = currentNode->next;
        for (int i = 0; i < n && nextNode != nullptr; i++) {
            Node *temp = nextNode;
            nextNode = nextNode->next;
            delete temp;
        }
        currentNode->next = nextNode;

        currentNode = nextNode;
    }

    return head;
}

int main() {
    Node *head = new Node(9);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next = new Node(1);

    cout << "Original list: ";
    printSLL(head);

    int m = 2, n = 1;
    head = skipMDeleteN(head, m, n);

    cout << "\nAfter applying skipMDeleteN (M=2, N=1): ";
    printSLL(head);

    return 0;
}
