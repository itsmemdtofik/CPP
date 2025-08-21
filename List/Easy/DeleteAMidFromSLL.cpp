#include <iostream>
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


void printSLL(const Node *head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    const Node *current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr)
            cout << " -> ";
        else
            cout << " -> None\n";
        current = current->next;
    }
}


Node *deleteInMiddle(Node *head, const int key) {
    if (head == nullptr) {
        return nullptr;
    }

    /* Case 1: Deletion at head */
    if (head->data == key) {
        const Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    /* Case 2: Search for node to delete */
    Node *previousNode = head;
    Node *currentNode = head->next;

    while (currentNode != nullptr) {
        if (currentNode->data == key) {
            previousNode->next = currentNode->next;
            delete currentNode;
            return head;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }


    cout << "Value " << key << " not found in the list." << endl;
    return head;
}


int main() {
    auto head = new Node(3);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(18);

    cout << "Original List:" << endl;
    printSLL(head);


    head = deleteInMiddle(head, 15);
    cout << "\nAfter deleting 15:" << endl;
    printSLL(head);


    head = deleteInMiddle(head, 99);
    cout << "\nAfter attempting to delete 99:" << endl;
    printSLL(head);


    head = deleteInMiddle(head, 3);
    cout << "\nAfter deleting 3 (head):" << endl;
    printSLL(head);

    return 0;
}
