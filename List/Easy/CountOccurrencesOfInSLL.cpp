#include <iostream>
using namespace std;

/*
 * Node for Singly Linked List
 */
class Node {
public:
    int data;
    Node *next;

    explicit Node(const int data) {
        this->data = data;
        this->next = nullptr;
    }
};

/*
 * Function to count occurrences of a key
 */
int countFrequencyOfGivenKey(const Node *head, const int key) {
    int count = 0;
    const Node *current = head;

    while (current != nullptr) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }

    return count;
}

int main() {
    auto head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    constexpr int key = 1;

    cout << "Occurrences of " << key << ": "
            << countFrequencyOfGivenKey(head, key) << endl;

    while (head != nullptr) {
        const Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
