/**
 🔹 1. Java Stack Operations 🔹

| **Operation**          | **Java (Legacy Stack)** | **Modern Java (Deque - Preferred)**          |
| ---------------------- | ----------------------- | -------------------------------------------- |
| **Push**               | `stack.push(item)`      | `deque.push(item)` or `deque.addFirst(item)` |
| **Pop**                | `stack.pop()`           | `deque.pop()` or `deque.removeFirst()`       |
| **Peek (top element)** | `stack.peek()`          | `deque.peek()` or `deque.peekFirst()`        |
| **Check if empty**     | `stack.isEmpty()`       | `deque.isEmpty()`                            |
| **Size**               | `stack.size()`          | `deque.size()`                               |

| Term     | Meaning                                                             |
| -------- | ------------------------------------------------------------------- |
| **Top**  | The most recently added element (last in) — top of the stack        |
| **Peek** | An operation to **look at the top** element **without removing** it |


Modern Java (Preferred: Deque for Stack):
"""

"""
📚 1. Python Stack Operations(Option: 1):
# Python does not have a dedicated Stack class, but list or deque can be used.

| **Operation**          | **Using `list`**     | **Using `collections.deque`** |
| ---------------------- | -------------------- | ----------------------------- |
| **Push**               | `stack.append(item)` | `stack.append(item)`          |
| **Pop**                | `stack.pop()`        | `stack.pop()`                 |
| **Peek (top element)** | `stack[-1]`          | `stack[-1]`                   |
| **Check if empty**     | `len(stack) == 0`    | `len(stack) == 0`             |
| **Size**               | `len(stack)`         | `len(stack)`                  |

| Term     | Meaning                                                             |
| -------- | ------------------------------------------------------------------- |
| **Top**  | The most recently added element (last in) — top of the stack        |
| **Peek** | An operation to **look at the top** element **without removing** it |

# Modern Python (Preferred: Deque for Stack): Since deque is optimized for fast appends/pops from both ends, it can also be used for stacks.
# In Python, we use collections.deque (double-ended queue) for efficient LIFO operations.

3. C++ Stack Operations
C++ provides std::stack (adapter container built on top of deque by default).
| **Operation**          | **C++ (`std::stack`)**                         |
| ---------------------- | ---------------------------------------------- |
| **Push**               | `st.push(item)`                                |
| **Pop**                | `st.pop()` *(removes top but does not return)* |
| **Peek (top element)** | `st.top()`                                     |
| **Check if empty**     | `st.empty()`                                   |
| **Size**               | `st.size()`                                    |
*/

#include <iostream>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

int main() {
    // -----------------------------
    // Stack Operations using std::stack
    // -----------------------------
    stack<int> st;

    st.push(10); // Push
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Stack Operations using std::stack:" << endl;

    cout << "Size of the stack: " << st.size() << endl;

    int top = st.top(); // Peek
    cout << "Top element of the stack: " << top << endl;

    st.pop(); // Pop
    cout << "Stack top after popping: " << st.top() << endl;

    bool isEmpty = st.empty();
    cout << "Is stack empty? " << boolalpha << isEmpty << endl;
    cout << "\n";

    // -----------------------------
    // Stack Operations using std::deque (LIFO)
    // -----------------------------
    deque<int> stack_deque;
    stack_deque.push_back(10);
    stack_deque.push_back(20);
    stack_deque.push_back(30);
    stack_deque.push_back(40);

    cout << "Stack Operations using std::deque:" << endl;
    cout << "Size: " << stack_deque.size() << endl;

    int peek = stack_deque.back();
    cout << "Peek element: " << peek << endl;

    int popped = stack_deque.back();
    stack_deque.pop_back();
    cout << "Popped element: " << popped << endl;

    peek = stack_deque.back();
    cout << "Peek after pop: " << peek << endl;

    isEmpty = stack_deque.empty();
    cout << "Is empty? " << boolalpha << isEmpty << endl;
    cout << "\n";

    // -----------------------------
    // Queue Operations using std::deque
    // -----------------------------
    deque<int> queue_deque;
    queue_deque.push_back(11); // Enqueue
    queue_deque.push_back(12);
    queue_deque.push_back(13);
    queue_deque.push_back(14);

    cout << "Queue Operations using std::deque:" << endl;

    int front = queue_deque.front(); // Peek front
    cout << "Front element: " << front << endl;

    if (!queue_deque.empty()) {
        int removed_item = queue_deque.front();
        queue_deque.pop_front(); // Dequeue
        cout << "Dequeued element: " << removed_item << endl;
    }

    isEmpty = queue_deque.empty();
    cout << "Is queue empty? " << boolalpha << isEmpty << endl;
    cout << "Size of the queue: " << queue_deque.size() << endl;

    return 0;
}

/**
 🔹 Stack & Queue Operations: Python vs C++ 🔹
 | **Data Structure** | **Operation**        | **Python (`list` / `deque`)**                                        | **C++ (`std::stack` / `std::deque`)**                       |
| ------------------ | -------------------- | -------------------------------------------------------------------- | ----------------------------------------------------------- |
| **Stack (LIFO)**   | Create               | `stack = []`<br>`from collections import deque`<br>`stack = deque()` | `stack<int> st;`<br>`deque<int> stack_deque;`               |
|                    | Push                 | `stack.append(item)`                                                 | `st.push(item);`<br>`stack_deque.push_back(item);`          |
|                    | Pop                  | `stack.pop()`                                                        | `st.pop();`<br>`stack_deque.pop_back();`                    |
|                    | Peek (top element)   | `stack[-1]`                                                          | `st.top();`<br>`stack_deque.back();`                        |
|                    | Check if empty       | `not stack`                                                          | `st.empty();`<br>`stack_deque.empty();`                     |
|                    | Size                 | `len(stack)`                                                         | `st.size();`<br>`stack_deque.size();`                       |
| **Queue (FIFO)**   | Create               | `from collections import deque`<br>`queue = deque()`                 | `deque<int> queue_deque;`<br>`queue<int> q;`                |
|                    | Enqueue              | `queue.append(item)`                                                 | `queue_deque.push_back(item);`<br>`q.push(item);`           |
|                    | Dequeue              | `queue.popleft()`                                                    | `queue_deque.pop_front();`<br>`q.pop();` (for `std::queue`) |
|                    | Peek (front element) | `queue[0]`                                                           | `queue_deque.front();`<br>`q.front();`                      |
|                    | Check if empty       | `not queue`                                                          | `queue_deque.empty();`<br>`q.empty();`                      |
|                    | Size                 | `len(queue)`                                                         | `queue_deque.size();`<br>`q.size();`                        |
*/
