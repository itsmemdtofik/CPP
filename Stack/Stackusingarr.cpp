/**
 * !Stack:
 * A stack is a linear data structure that follows the Last In, First Out (LIFO) principle.
 * This means that the last element added to the stack is the first one to be removed.
 *
 * ? Operations on a Stack:
 * * 1. Push(): Add an item to the top of stack.
 * * 2. Pop(): Remove an item from the top of stack.
 * * 3. Peek(): Returns the top without removing it.
 * * 4. isEmpty(): Check is stack is empty or not.
 * * 5. size(): Returns the number of elements in the stack.
 *
 * TODO: Real world example: 1.Browser History, 2.Undo Functions in text editor.
 *
 * @param Application: Depth First Search in graphs.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Define stack size

class Stack
{
private:
    int top;           // Index of top element
    int arr[MAX_SIZE]; // Stack array

public:
    Stack() : top(-1) {} // Constructor initializing top to -1

    void overflow()
    {
        cout << "Overflow Condition: Stack is full." << endl;
    }

    void underflow()
    {
        cout << "Underflow Condition: Stack is empty." << endl;
    }

    void push()
    {
        if (top == MAX_SIZE - 1)
        {
            overflow();
        }
        else
        {
            int element;
            cout << "Enter the element to insert into the stack: ";
            cin >> element;
            arr[++top] = element; // Increment top and insert element
            cout << "Element pushed: " << element << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            underflow();
        }
        else
        {
            cout << "Element popped: " << arr[top] << endl;
            top--; // Decrement top
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements:" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack stack;
    int choice;

    while (true)
    {
        cout << "--------------------------" << endl;
        cout << "1 - Push" << endl;
        cout << "2 - Pop" << endl;
        cout << "3 - Display" << endl;
        cout << "4 - Exit" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            stack.push();
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}