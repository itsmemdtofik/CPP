#include <iostream>
#include <stdexcept>
using namespace std;


class ListNode {
public:
    int data;
    ListNode *next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};


class Queue {
private:
    ListNode *front;
    ListNode *rear;
    int _size;

public:
    Queue() {
        front = rear = nullptr;
        _size = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int size() {
        return _size;
    }

    void enqueue(int data) {
        ListNode *newNode = new ListNode(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        _size++;
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        int data = front->data;
        ListNode *temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        _size--;
        return data;
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        ListNode *current = front;
        cout << "Queue: ";
        while (current) {
            cout << current->data;
            if (current->next) cout << " -> ";
            else cout << " -> null";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.display();

    cout << "Front element: " << queue.peek() << endl;
    cout << "Queue size: " << queue.size() << endl;

    return 0;
}
