/**
Multiply two numbers represented by Linked Lists
Given two numbers represented by linked lists, The task is to return the multiplication of these two linked lists.

Examples:

Input : head1 : 1->0->0 , head2 : 1->0
Output: 1000
Explanation: head1 represents 100 and head2 represents the number 10, 100 x 10 = 1000

Time Complexity: O(max(n1, n2)), where n1 and n2 represents the number of nodes present in the first and second linked list respectively.
Auxiliary Space: O(1)
*/

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};

/* ------------------ Multiply Two Numbers Represented by Linked Lists ------------------ */
long long multiplyTwoNumbers(Node *head1, Node *head2) {
    const long long MOD = 1000000007; /* Large prime to prevent overflow */
    long long num1 = 0, num2 = 0;

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    while (ptr1 != nullptr) {
        num1 = (num1 * 10 + ptr1->data) % MOD;
        ptr1 = ptr1->next;
    }

    while (ptr2 != nullptr) {
        num2 = (num2 * 10 + ptr2->data) % MOD;
        ptr2 = ptr2->next;
    }

    return (num1 * num2) % MOD;
}


int main() {
    /* Create first list: 1 -> 0 -> 0 (represents 100) */
    Node *head1 = new Node(1);
    head1->next = new Node(0);
    head1->next->next = new Node(0);

    /* Create second list: 1 -> 0 (represents 10) */
    Node *head2 = new Node(1);
    head2->next = new Node(0);

    cout << "Product of the two numbers: " << multiplyTwoNumbers(head1, head2) << endl;

    return 0;
}
