/**
* <pre>
* !Reverse Linked List
* Given a linked list, the task is to reverse the linked list by changing the links between nodes.
* The idea is to reverse the links of all nodes using three pointers:
*
* Input: head: 1 -> 2 -> 3 -> 4 -> NULL
* Output: head: 4 -> 3 -> 2 -> 1 -> NULL
* Explanation: Reversed Linked List: 4 -> 3 -> 2 -> 1 -> null
*
* !Approach1: Using Iterative Method - O(n) Time and O(1) Space
* !Approach2: Using Stack - O(n) Time and O(n) Space
* prev: pointer to keep track of the previous node
* temp1: pointer to keep track of the current node
* temp2: pointer to keep track of the next node
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


Node *reverseSingleLinkedListUsingTwoPointer(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *currentNode = head;
    Node *previousNode = nullptr;
    Node *nextNode = nullptr;

    while (currentNode != nullptr) {
        nextNode = currentNode->next; /* Store next */
        currentNode->next = previousNode; /* Reverse link */
        previousNode = currentNode; /* Move previous forward */
        currentNode = nextNode; /* Move current forward */
    }

    return previousNode;
}


void printSLL(Node *head) {
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked list:";
    printSLL(head);

    head = reverseSingleLinkedListUsingTwoPointer(head);

    cout << "Reversed Linked List:";
    printSLL(head);

    return 0;
}
