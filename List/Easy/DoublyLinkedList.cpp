#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    explicit Node(const int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node *head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }


    void insertAtBeginning(int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }


    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }


    void deleteFromBeginning() {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
    }


    void deleteFromEnd() {
        if (!head)
            return;
        Node *temp = head;
        if (!temp->next) {
            delete temp;
            head = nullptr;
            return;
        }
        while (temp->next)
            temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }


    bool search(int key) {
        Node *temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }


    void traverseForward() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }


    void traverseBackward() {
        if (!head)
            return;
        Node *temp = head;
        while (temp->next)
            temp = temp->next; // go to last
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }


    void removeDuplicates() {
        if (!head)
            return;
        unordered_set<int> seen;
        Node *temp = head;
        while (temp) {
            if (seen.count(temp->data)) {
                Node *toDelete = temp;
                temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                temp = temp->next;
                delete toDelete;
            } else {
                seen.insert(temp->data);
                temp = temp->next;
            }
        }
    }


    void reverse() {
        Node *current = head;
        Node *temp = nullptr;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp)
            head = temp->prev;
    }


    static Node *mergeSorted(Node *h1, Node *h2) {
        if (!h1)
            return h2;
        if (!h2)
            return h1;

        if (h1->data < h2->data) {
            h1->next = mergeSorted(h1->next, h2);
            if (h1->next)
                h1->next->prev = h1;
            return h1;
        } else {
            h2->next = mergeSorted(h1, h2->next);
            if (h2->next)
                h2->next->prev = h2;
            return h2;
        }
    }


    Node *clone() {
        if (!head)
            return nullptr;
        Node *temp = head;
        Node *newHead = new Node(temp->data);
        Node *newCurr = newHead;
        temp = temp->next;
        while (temp) {
            Node *copy = new Node(temp->data);
            newCurr->next = copy;
            copy->prev = newCurr;
            newCurr = copy;
            temp = temp->next;
        }
        return newHead;
    }


    bool detectLoop() {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }


    Node *getHead() { return head; }
};


int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.insertAtEnd(50);
    dll.insertAtEnd(60);
    dll.insertAtEnd(70);

    cout << "Original List (Forward):\n";
    dll.traverseForward();

    cout << "Original List (Backward):\n";
    dll.traverseBackward();

    dll.insertAtBeginning(10);
    cout << "After inserting 10 at beginning:\n";
    dll.traverseForward();

    dll.deleteFromBeginning();
    cout << "After deleting from beginning:\n";
    dll.traverseForward();

    dll.deleteFromEnd();
    cout << "After deleting from end:\n";
    dll.traverseForward();

    cout << "Searching 40: " << (dll.search(40) ? "Found\n" : "Not Found\n");

    dll.removeDuplicates();
    cout << "After removing duplicates:\n";
    dll.traverseForward();

    dll.reverse();
    cout << "After reversing DLL:\n";
    dll.traverseForward();

    return 0;
}
