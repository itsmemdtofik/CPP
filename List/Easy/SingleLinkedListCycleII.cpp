/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle.
Note that pos is not passed as a parameter.

Do not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
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


Node *detectCycle(Node *head) {
    if (!head || !head->next)
        return nullptr;

    Node *slow = head;
    Node *fast = head;

    /* Phase 1: Detect if cycle exists */
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            /* Phase 2: Find start of cycle */
            Node *temp1 = head;
            Node *temp2 = slow;

            while (temp1 != temp2) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1; /* Start of cycle */
        }
    }

    return nullptr;
}

int main() {
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);


    head->next->next->next->next = head->next;

    Node *cycle_start = detectCycle(head);

    if (cycle_start)
        cout << "Cycle starts at node with value: " << cycle_start->data << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
