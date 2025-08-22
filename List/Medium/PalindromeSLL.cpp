/**
* <pre>
* !Palindrome Linked List
* Given a singly linked list. The task is to check if the given linked list is palindrome or not.
*
* ! Approach1: Using Stack - O(n) Time and O(n) Space
* ! Approach2: Using Iterative Method (Slow-Fast) - O(n) Time and O(1) Space
* </pre>
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};

/* ------------------ Approach 1: Using Stack ------------------ */
bool isPalindromeUsingStack(Node *head) {
    stack<int> st;
    Node *current = head;

    /* Push all values onto the stack */
    while (current != nullptr) {
        st.push(current->data);
        current = current->next;
    }

    /* Compare with original list */
    current = head;
    while (current != nullptr) {
        if (current->data != st.top()) return false;
        st.pop();
        current = current->next;
    }

    return true;
}

/* ------------------ Approach 2: Iterative (Reverse Second Half) ------------------ */
bool isPalindromeIterative(Node *head) {
    if (!head || !head->next) return true;

    /* Step 1: Find middle */
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Step 2: Reverse second half */
    Node *prev = nullptr;
    Node *curr = slow;
    while (curr) {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    /* Step 3: Compare both halves */
    Node *first = head;
    Node *second = prev;
    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

/* ------------------ Approach 3: Using Vector & Two Pointers ------------------ */
bool isPalindromeUsingVector(Node *head) {
    vector<int> values;
    Node *current = head;
    while (current) {
        values.push_back(current->data);
        current = current->next;
    }

    int left = 0, right = values.size() - 1;
    while (left < right) {
        if (values[left] != values[right]) return false;
        left++;
        right--;
    }

    return true;
}


int main() {
    /* Create a list: 1 -> 2 -> 3 -> 2 -> 1 -> 10 */
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    if (isPalindromeUsingStack(head))
        cout << "List is Palindrome (Stack method)" << endl;
    else
        cout << "List is not Palindrome (Stack method)" << endl;

    if (isPalindromeIterative(head))
        cout << "List is Palindrome (Iterative method)" << endl;
    else
        cout << "List is not Palindrome (Iterative method)" << endl;

    if (isPalindromeUsingVector(head))
        cout << "List is Palindrome (Vector method)" << endl;
    else
        cout << "List is not Palindrome (Vector method)" << endl;

    return 0;
}
