/*
Delete a Node from linked list without head pointer

You are given a singly linked list and pointer which is pointing to the node which is required to be deleted.
Any information about the head pointer or any other node is not given.
You need to write a function to delete that node from the linked list.
Your function will take only one argument, i.e., a pointer to the node which is to be deleted

Note: No head reference is given to you. It is guaranteed that the node to be deleted is not the last node:
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


void deleteNodeWithoutHead(Node *current) {
    if (current == nullptr) {
        return;
    } else if (current->next == nullptr) {
        cout << "This is last node, require head, can not be freed\n";
        return;
    }


    Node *nextNode = current->next;
    current->data = nextNode->data;

    current->next = nextNode->next;
    delete nextNode;
}


class DeleteNodeWithoutHead {
public:
    Node *head;

    DeleteNodeWithoutHead() {
        head = nullptr;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main() {
    DeleteNodeWithoutHead llist;


    llist.push(20);
    llist.push(4);
    llist.push(15);
    llist.push(35);

    cout << "Initial Linked List: \n";
    llist.printList();


    Node *del_node = llist.head->next;

    deleteNodeWithoutHead(del_node);

    cout << "Final Linked List after deletion of 15: \n";
    llist.printList();

    return 0;
}
