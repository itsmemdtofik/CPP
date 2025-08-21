/*
     * <pre>
     * !Delete middle of linked list
     * Given a singly linked list, the task is to delete the middle node of the list.
     * If the list contains an even number of nodes, there will be two middle nodes. In this case, delete the second middle node.
     * If the linked list consists of only one node, then return NULL.
     *
     * @param Example:
     * Input: LinkedList: 1->2->3->4->5
     * Output: 1->2->4->5
     *
     * !Approach1: Using Two-Pass Traversal - O(n) Time and O(1) space
     * </pre>
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


Node *deleteMidNodeFromSingleLinkedList(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node *slow = head;
    const Node *fast = head;
    Node *previousNode = nullptr;


    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        previousNode = slow;
        slow = slow->next;
    }


    if (previousNode != nullptr) {
        previousNode->next = slow->next;
        delete slow;
    }

    return head;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    /* head->next->next->next->next->next = new Node(6); // uncomment for even case */

    cout << "Original list: ";
    printSLL(head);

    head = deleteMidNodeFromSingleLinkedList(head);

    cout << "\nAfter deleting middle node: ";
    printSLL(head);

    return 0;
}
