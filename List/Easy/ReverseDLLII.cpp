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
#include <stack>
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

Node *reverseDoublyLinkedListUsingStack(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    stack<Node *> st;
    Node *currentNode = head;

    /* Push all nodes onto the stack */
    while (currentNode != nullptr) {
        st.push(currentNode);
        currentNode = currentNode->next;
    }

    /* Pop nodes from the stack and reverse the list */
    Node *newHead = st.top();
    st.pop();
    currentNode = newHead;

    while (!st.empty()) {
        Node *nextNode = st.top();
        st.pop();
        currentNode->next = nextNode;
        nextNode->prev = currentNode;
        currentNode = nextNode;
    }

    currentNode->next = nullptr; /* Last node's next is nullptr */
    return newHead;
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
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    cout << "Original list:" << endl;
    printDLL(head);

    head = reverseDoublyLinkedListUsingStack(head);

    cout << "Reversed list:" << endl;
    printDLL(head);

    return 0;
}
