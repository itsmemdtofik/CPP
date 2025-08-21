/*
 * <pre>
 * !Program for Nth node from the end of a Linked List
 * Given a Linked List of M nodes and a number N,
 * find the value at the Nth node from the end of the Linked List.
 * If there is no Nth node from the end, print -1.
 *
 * @param Examples:
 * Input: 1 -> 2 -> 3 -> 4, N = 3
 * Output: 2
 * Explanation: Node 2 is the third node from the end of the linked list.
 *
 * Input: 35 -> 15 -> 4 -> 20, N = 4
 * Output: 35
 * Explanation: Node 35 is the fourth node from the end of the linked list.
 *
 * !Approach: By Finding the length of list - Two Pass - O(M) Time and O(1) Space
 * The idea is to count the number of nodes in linked list in the first pass, say len.
 * In the second pass, return the (len - n + 1)th nodes from beginning of the Linked List.
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

class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = nullptr;
    }

    /* Append a node at the end */
    void append(int data) {
        Node *new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }

        Node *last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }

    /* Get Nth node from end using two-pass approach */
    int get_nth_from_end(int n) const {
        int length = 0;
        Node *currentNode = head;

        /* First pass: find length of list */
        while (currentNode != nullptr) {
            length++;
            currentNode = currentNode->next;
        }

        /* If n is greater than length, return -1 */
        if (n > length) {
            return -1;
        }

        /* Second pass: get (length - n + 1)th node from start */
        currentNode = head;
        for (int i = 0; i < length - n; i++) {
            currentNode = currentNode->next;
        }

        return currentNode->data;
    }
};

int main() {
    LinkedList llist1;
    int arr1[] = {1, 2, 3, 4};
    for (int val: arr1)
        llist1.append(val);
    cout << "Output: " << llist1.get_nth_from_end(3) << endl;

    LinkedList llist2;
    int arr2[] = {35, 15, 4, 20};
    for (int val: arr2)
        llist2.append(val);
    cout << "Output: " << llist2.get_nth_from_end(4) << endl;

    return 0;
}
