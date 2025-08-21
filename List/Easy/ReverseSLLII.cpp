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
* !Approach1: Using Iterative Method(two-pointer) - O(n) Time and O(1) Space
* !Approach2: Using Stack - O(n) Time and O(n) Space
* Push all nodes onto the stack
* Pop the last node from the stack (which was the last in original list)
* Start popping the nodes and push them at the end of the linked list in the same order until the stack is empty.
* Update the current->next pointer of last node in the stack by NULL.
* </pre>
*/

#include <iostream>
#include <stack>
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


Node *reverseSingleLinkedListUsingStack(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    stack<Node *> stk;
    Node *currentNode = head;


    while (currentNode != nullptr) {
        stk.push(currentNode);
        currentNode = currentNode->next;
    }


    Node *newHead = stk.top();
    stk.pop();
    currentNode = newHead;


    while (!stk.empty()) {
        currentNode->next = stk.top();
        stk.pop();
        currentNode = currentNode->next;
    }


    currentNode->next = nullptr;

    return newHead;
}

// Function to print singly linked list
void printList(Node *node) {
    while (node != nullptr) {
        cout << " " << node->data << " ->";
        node = node->next;
    }
    cout << " NULL" << endl;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked List:";
    printList(head);

    head = reverseSingleLinkedListUsingStack(head);

    cout << "Reversed Linked List:";
    printList(head);

    return 0;
}
