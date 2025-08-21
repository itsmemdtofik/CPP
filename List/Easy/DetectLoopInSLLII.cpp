/*
 * <pre>
 * !Detect Loop or Cycle in Linked List
 * Given a singly linked list, check if the linked list has a loop (cycle) or not.
 * A loop means that the last node of the linked list is connected back to a node in the same list.
 *
 * Input: head: 1 -> 3 -> 4 -> 3
 * Output: true
 * Input: head: 1 -> 8 -> 3 -> 4 -> NULL
 * Output: false
 * !Approach: Using HashSet - O(n) Time and O(n) Space
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


bool detectLoopUsingTwoPointer(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);


    head->next->next->next = head->next;

    if (detectLoopUsingTwoPointer(head)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
