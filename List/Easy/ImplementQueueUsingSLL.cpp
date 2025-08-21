/*
Queue - Linked List Implementation

In this article, the Linked List implementation of the queue data structure is discussed and implemented. Print '-1' if the queue is empty.
Approach: To solve the problem follow the below idea:
we maintain two pointers, front and rear. The front points to the first item of the queue and rear points to the last item.

enQueue(): This operation adds a new node after the rear and moves the rear to the next node.
deQueue(): This operation removes the front node and moves the front to the next node.

*/

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


class Queue {
private:
    Node *front;
    Node *rear;

public:
    Queue() {
        front = rear = nullptr;
    }


    bool isEmpty() {
        return front == nullptr;
    }


    void enqueue(const int data) {
        const auto newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        printQueue();
    }


    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return -1;
        }
        const Node *temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        const int removedData = temp->data;
        delete temp;
        printQueue();
        return removedData;
    }


    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        cout << "Current Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    Queue q;


    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);


    q.dequeue();
    q.dequeue();


    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);


    q.dequeue();

    return 0;
}
