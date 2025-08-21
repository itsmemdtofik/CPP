/*
Array implementation of queue - Simple:

To implement a queue of size n using an array, the operations are as follows:
Enqueue: Adds new elements to the end of the queue. Checks if the queue has space before insertion, then increments the size.
Dequeue: Removes the front element by shifting all remaining elements one position to the left. Decrements the queue size after removal.
getFront: Returns the first element of the queue if it's not empty. Returns -1 if the queue is empty.
Display: Iterates through the queue from the front to the current size and prints each element.

*/

#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> q;

public:
    bool is_empty() {
        return q.empty();
    }

    /* Enqueue: add element at the end */
    void enqueue(int x) {
        q.push_back(x);
    }

    /* Dequeue: remove element from the front */
    void dequeue() {
        if (!is_empty()) {
            q.erase(q.begin()); /* remove first element */
        }
    }

    int get_front() {
        return is_empty() ? -1 : q[0];
    }


    void display() {
        for (const int x: q) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.get_front() << endl;

    q.dequeue();
    q.enqueue(4);

    q.display();

    return 0;
}
