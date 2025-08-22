/**
* <pre>
* ! Linked List Cycle II
* Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
* Detect the start node of a cycle in a linked list, if one exists. Otherwise, return null.
* @param Note: Do not modify the linked list.
* </pre>
*/

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};


Node *getStartNodeOfCycle(Node *head) {
    if (!head || !head->next) return nullptr;

    Node *slow = head;
    Node *fast = head;

    /* Step 1: Detect if there's a cycle using slow & fast pointers */
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            /* Step 2: Cycle detected, find start of cycle */
            Node *current = head;
            while (current != slow) {
                current = current->next;
                slow = slow->next;
            }
            return current; /* Start of cycle */
        }
    }

    return nullptr;
}


void printCycleStart(Node *head) {
    if (head)
        cout << "Cycle starts at node with data: " << head->data << endl;
    else
        cout << "No cycle detected" << endl;
}


int main() {
    /* Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle starts again at 3) */
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; /* Cycle at node 3 */

    Node *start_node = getStartNodeOfCycle(head);
    printCycleStart(start_node);

    return 0;
}
