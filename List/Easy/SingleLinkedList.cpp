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


void printSLL(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}


Node *insertAtBeginning(Node *head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    return newNode;
}


Node *insertAtMidOfEvenOdd(Node *head, int data) {
    if (!head)
        return new Node(data);

    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newNode = new Node(data);

    if (!fast) {
        /* Even length: insert before second middle */
        newNode->next = slow;
        if (prev) {
            prev->next = newNode;
            return head;
        } else {
            return newNode; /* Only two nodes, insert at beginning */
        }
    } else {
        /* Odd length: insert after middle */
        newNode->next = slow->next;
        slow->next = newNode;
        return head;
    }
}


Node *insertAtEnd(Node *head, int data) {
    Node *newNode = new Node(data);
    if (!head)
        return newNode;

    Node *current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
    return head;
}


Node *deleteAtBeginning(Node *head) {
    if (!head)
        return nullptr;
    Node *temp = head->next;
    delete head;
    return temp;
}


Node *deleteAtMidOfEvenOdd(Node *head) {
    if (!head || !head->next)
        return nullptr;

    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev)
        prev->next = slow->next;
    delete slow;
    return head;
}


Node *deleteAtEnd(Node *head) {
    if (!head)
        return nullptr;
    if (!head->next) {
        delete head;
        return nullptr;
    }

    Node *current = head;
    Node *prev = nullptr;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    prev->next = nullptr;
    delete current;
    return head;
}

int main() {
    Node *head = new Node(20);
    head->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next->next = new Node(50);
    head->next->next->next->next = new Node(60);
    head->next->next->next->next->next = new Node(70);

    head = insertAtBeginning(head, 10);
    cout << "After inserting 10 at beginning: ";
    printSLL(head);

    head = insertAtMidOfEvenOdd(head, 80);
    cout << "After inserting 80 at middle: ";
    printSLL(head);

    head = insertAtEnd(head, 90);
    cout << "After inserting 90 at end: ";
    printSLL(head);

    head = deleteAtBeginning(head);
    cout << "After deleting from beginning: ";
    printSLL(head);

    head = deleteAtMidOfEvenOdd(head);
    cout << "After deleting from middle: ";
    printSLL(head);

    head = deleteAtMidOfEvenOdd(head);
    cout << "After deleting from middle again: ";
    printSLL(head);

    head = deleteAtEnd(head);
    cout << "After deleting from end: ";
    printSLL(head);

    return 0;
}
