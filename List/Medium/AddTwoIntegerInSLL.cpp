/**
Add Two Numbers Represented as Linked List
Given two numbers represented as two lists, the task is to return the sum of two lists.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Input: num1 = 4 -> 5, num2 = 3 -> 4 -> 5
Output: 3 -> 9 -> 0
Explanation: Sum of 45 and 345 is 390.

Time: O(n + m)
Space: O(n + m) due to call stack or auxiliary stacks.
*/
#include <iostream>
#include <string>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


long long listToNumber(Node *head) {
    long long num = 0;
    Node *current = head;
    while (current != nullptr) {
        num = num * 10 + current->data;
        current = current->next;
    }
    return num;
}


Node *numberToList(long long num) {
    if (num == 0) return new Node(0);

    string s = to_string(num);
    Node *dummy = new Node(0);
    Node *current = dummy;

    for (char c: s) {
        current->next = new Node(c - '0'); // convert char -> int
        current = current->next;
    }
    return dummy->next;
}


Node *addTwoLists(Node *head1, Node *head2) {
    long long num1 = listToNumber(head1);
    long long num2 = listToNumber(head2);
    long long total = num1 + num2;
    return numberToList(total);
}

// ------------------ Main ------------------
int main() {
    // num1 = 4 -> 5 (i.e., 45)
    Node *num1 = new Node(4);
    num1->next = new Node(5);

    // num2 = 3 -> 4 -> 5 (i.e., 345)
    Node *num2 = new Node(3);
    num2->next = new Node(4);
    num2->next->next = new Node(5);

    cout << "Input List 1: ";
    printList(num1);

    cout << "Input List 2: ";
    printList(num2);

    Node *result = addTwoLists(num1, num2);

    cout << "Result (Sum): ";
    printList(result);

    return 0;
}
