#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {
    }
};


void printSLL(Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

/* ------------------ Remove All Duplicates from Sorted List ------------------ */
Node *removeAllDuplicates(Node *head) {
    /* Dummy node to handle edge cases at head */
    Node *dummy = new Node(0);
    dummy->next = head;

    Node *prev = dummy; /* Tracks last node before duplicate sequence */
    Node *curr = head; /* Current node being examined */

    while (curr) {
        bool isDuplicate = false;

        /* Move curr to the last node of duplicates */
        while (curr->next && curr->data == curr->next->data) {
            Node *temp = curr;
            curr = curr->next;
            delete temp; /* free memory of duplicate node */
            isDuplicate = true;
        }

        if (isDuplicate) {
            /* Skip all duplicates */
            Node *temp = curr;
            curr = curr->next;
            delete temp; /* remove last duplicate node */
            prev->next = curr; /* connect previous node to next distinct */
        } else {
            prev = prev->next;
            curr = curr->next;
        }
    }

    Node *newHead = dummy->next;
    delete dummy; /* free dummy */
    return newHead;
}


int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(5);

    cout << "Before Removing Duplicates:" << endl;
    printSLL(head);

    head = removeAllDuplicates(head);

    cout << "After Removing Duplicates:" << endl;
    printSLL(head);

    return 0;
}
