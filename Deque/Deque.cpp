/**
 * !Deque in C++
 *
 * A deque (stands for double-ended queue) however, is more flexible, as elements can be added and removed from both ends (at the front and the back). You can also access elements by index numbers.
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
#include <deque>

int main()
{

    std::deque<std::string> deque = {"apple", "banana", "mango"};

    std::cout << "Printing the deque elements : " << "\n";
    for (std::string deq : deque)
    {
        std::cout << deq << "\n";
    }

    /**
     * We can access the element by index.
     */
    std::cout << "Accessing the element by index : " << "\n";
    std::cout << deque[0] << "\n";
    std::cout << deque[1] << "\n";

    /**
     * We can also access the first and last element using front() and back().
     * We can also access the element at specified position using at().
     *
     */
    std::cout << "Printing first and last element by using front() and back() : " << "\n";
    std::cout << deque.front() << "\n";
    std::cout << deque.back() << "\n";

    /**
     * We can also set or modify the deuque by using at() or using index.
     */

    deque[0] = "Western Digital";
    deque[deque.size() - 1] = "Sandisk";
    std::cout << "-----New Deque's Element are-----" << "\n";
    for (std::string d : deque)
    {
        std::cout << d << "\n";
    }
    deque.at(0) = "IBM";
    deque.at(2) = "Google";

    std::cout << "-----New Deque's Element are-----" << "\n";
    for (std::string d : deque)
    {
        std::cout << d << "\n";
    }

    /**
     * We can add element from begining and end using push_front() and push_back()
     */

    deque.push_back("Amazon");
    deque.push_front("Microsoft");
    std::cout << "-----New Deque's Element are-----" << "\n";
    for (std::string d : deque)
    {
        std::cout << d << "\n";
    }

    /**
     * We can also remove the element from begining and end using pop_front() and pop_back()
     */

     deque.pop_back();
     deque.pop_front();
     std::cout << "-----New Deque's Element are-----" << "\n";
     for (std::string d : deque)
     {
         std::cout << d << "\n";
     }
    return 0;
}