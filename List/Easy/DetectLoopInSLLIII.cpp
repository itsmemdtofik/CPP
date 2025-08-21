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


Node *detectLoopIII(Node *head) {
    Node *slow = head;
    Node *fast = head;

    /* First phase: detect loop */
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            /* Second phase: find the start of the loop */
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; /* starting node of the loop */
        }
    }
    return nullptr;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);


    head->next->next->next = head->next;

    Node *loopNode = detectLoopIII(head);

    if (loopNode != nullptr) {
        cout << "True, loop starts at node with value: " << loopNode->data << "\n";
    } else {
        cout << "False\n";
    }

    return 0;
}
