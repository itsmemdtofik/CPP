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
#include <unordered_set>
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


bool detectLoopUsingSet(Node *head) {
    unordered_set<Node *> seen;

    Node *currentNode = head;
    while (currentNode != nullptr) {
        if (seen.find(currentNode) != seen.end()) {
            return true;
        }
        seen.insert(currentNode);
        currentNode = currentNode->next;
    }

    return false;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);


    head->next->next->next = head->next;

    if (detectLoopUsingSet(head)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
