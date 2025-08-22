/**
Intersection point of two Linked Lists

Given two singly linked lists that merge into a single Y-shaped list.
The two lists initially have distinct paths but eventually converge at a common node,
forming a Y-shape, the task is to find and return the node where the two lists merge.
*/

#include <iostream>
#include <unordered_set>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};


int getCount(Node *head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

/* ------------------ Approach 1: Nested Loop ------------------ */
Node *getIntersectionNestedLoop(Node *head1, Node *head2) {
    for (Node *ptr2 = head2; ptr2 != nullptr; ptr2 = ptr2->next) {
        for (Node *ptr1 = head1; ptr1 != nullptr; ptr1 = ptr1->next) {
            if (ptr1 == ptr2) return ptr2;
        }
    }
    return nullptr;
}

/* ------------------ Approach 2: Using Hashing ------------------ */
Node *getIntersectionHashing(Node *head1, Node *head2) {
    unordered_set<Node *> seen;
    for (Node *ptr1 = head1; ptr1 != nullptr; ptr1 = ptr1->next)
        seen.insert(ptr1);

    for (Node *ptr2 = head2; ptr2 != nullptr; ptr2 = ptr2->next)
        if (seen.find(ptr2) != seen.end()) return ptr2;

    return nullptr;
}

/* ------------------ Helper for Difference Method ------------------ */
Node *getIntersectionByDifference(int diff, Node *head1, Node *head2) {
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    for (int i = 0; i < diff; i++) {
        if (!ptr1) return nullptr;
        ptr1 = ptr1->next;
    }

    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return nullptr;
}

/* ------------------ Approach 3: Difference Method ------------------ */
Node *getIntersectionByDifferenceMethod(Node *head1, Node *head2) {
    int len1 = getCount(head1);
    int len2 = getCount(head2);

    if (len1 > len2)
        return getIntersectionByDifference(len1 - len2, head1, head2);
    else
        return getIntersectionByDifference(len2 - len1, head2, head1);
}

/* ------------------ Approach 4: Two Pointer Switching ------------------ */
Node *getIntersectionTwoPointer(Node *head1, Node *head2) {
    if (!head1 || !head2) return nullptr;

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 != nullptr) ? ptr1->next : head2;
        ptr2 = (ptr2 != nullptr) ? ptr2->next : head1;
    }

    return ptr1; /* returns intersection node or nullptr */
}


int main() {
    /* List A: 10 -> 15 -> 30 */
    Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);

    /* List B: 3 -> 6 -> 9 */
    Node *head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);

    /* Connecting B to A at node 15 (shared reference) */
    head2->next->next->next = head1->next;

    Node *intersection = getIntersectionTwoPointer(head1, head2);
    if (intersection)
        cout << "Intersection Point: " << intersection->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
