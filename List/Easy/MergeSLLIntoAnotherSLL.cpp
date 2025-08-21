/*
 * <pre>
 * !Merges two linked lists at alternate positions.
 * Given two singly linked lists, The task is to insert nodes of the second list
 * into the first list at alternate positions of the first list and leave the
 * remaining nodes of the second list if it is longer.
 *
 * @param Example:
 * Input: head1: 1->2->3 , head2: 4->5->6->7->8
 * Output: head1: 1->4->2->5->3->6 , head2: 7->8
 *
 * !Approach: Using Iterative Method – O(n) Time and O(1) Space
 * The idea is to start traversing from the beginning of both lists.
 * For each step, take a node from the second list and insert it after a node from the first list.
 * This process continues until we reach the end of one or both lists.
 * If the second list is longer, remaining nodes will be kept as it is second list.
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

void printSLL(Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data;
        if (current->next)
            cout << " -> ";
        else
            cout << " -> NULL";
        current = current->next;
    }
    cout << endl;
}

pair<Node *, Node *> merge(Node *head1, Node *head2) {
    Node *currentNode1 = head1;
    Node *currentNode2 = head2;

    while (currentNode1 != nullptr && currentNode2 != nullptr) {
        Node *temp1 = currentNode1->next;
        Node *temp2 = currentNode2->next;

        currentNode2->next = currentNode1->next;
        currentNode1->next = currentNode2;

        currentNode1 = temp1;
        currentNode2 = temp2;
    }

    return {head1, currentNode2};
}

int main() {
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node *head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(7);
    head2->next->next->next->next = new Node(8);

    pair<Node *, Node *> result = merge(head1, head2);

    cout << "Merged List 1: ";
    printSLL(result.first);

    cout << "Remaining List 2: ";
    printSLL(result.second);

    return 0;
}
