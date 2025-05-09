/**
 * ! Stack in C++
 * A stack stores multiple elements in a specific order, called LIFO.
 * Since elements are added and removed from the top, you can only access the element at the top of the stack.
 * Can not access by index.
 */

/*
 * 1  | Data Structure | Description
 * 2  | -------------- | ---------------------------------------------------------
 * 3  | Vector         | Stores elements like an array but can dynamically change
 * 4  |                | in size. Adding/removing elements is usually done at the
 * 5  |                | end. Elements can be accessed by index.
 * 6  | List           | Stores elements sequentially, where each element is
 * 7  |                | connected to the next. Adding/removing can be done at
 * 8  |                | both ends. Not accessible by index.
 * 9  | Stack          | Stores elements in LIFO (Last In, First Out) order,
 * 10 |                | where elements can only be added/removed from the top.
 * 11 |                | Not accessible by index.
 * 12 | Queue          | Stores elements in FIFO (First In, First Out) order,
 * 13 |                | where elements are added at the end and removed from
 * 14 |                | the front. Not accessible by index.
 * 15 | Deque          | Stores elements in a double-ended queue, where elements
 * 16 |                | can be added/removed from both ends. Accessible by index.
 * 17 | Set            | Stores unique elements. Not accessible by index.
 * 18 | Map            | Stores elements in "key/value" pairs. Accessible by keys
 * 19 |                | (not by index).
 */

#include <iostream>
#include <string>
#include <stack>

int main()
{

    std::stack<std::string> stack;

    stack.push("apple");
    stack.push("mango");
    stack.push("banana");
    stack.push("orange");

    std::cout << "The top of the element is : " << stack.top() << "\n";

    std::cout << "After removing the element from the top :\n";
    stack.pop();
    std::cout << "The top of the element is : " << stack.top() << "\n";

    return 0;
}