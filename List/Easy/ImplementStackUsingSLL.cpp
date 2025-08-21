#include <iostream>
#include <stdexcept>
using namespace std;


class StackNode {
public:
    int data;
    StackNode *next;

    StackNode(int val) {
        data = val;
        next = nullptr;
    }
};


class Stack {
private:
    StackNode *top;
    int _size;

public:
    Stack() {
        top = nullptr;
        _size = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        return _size;
    }

    void push(int data) {
        StackNode *newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
        _size++;
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        int data = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        _size--;
        return data;
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack: null" << endl;
            return;
        }

        StackNode *current = top;
        cout << "Stack: ";
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
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Popped: " << stack.pop() << endl;
    stack.display();

    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.size() << endl;

    return 0;
}
