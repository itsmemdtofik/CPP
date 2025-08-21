/**
 * !List in C++
 *
 * Store multiple elements of the same type and dynamically grow in size.
 *
 * However, two major differences between lists and vectors are:
 * You can add and remove elements from both the beginning and at the end of a list, while vectors are generally optimized for adding and removing at the end.
 * Unlike vectors, a list does not support random access, meaning you cannot directly jump to a specific index, or access elements by index numbers.
 *
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
#include <list>

int main() {
    std::list<std::string> list = {"Apple", "Mango", "Orange", "Banana"};
    for (std::string li: list) {
        std::cout << li << "\n";
    }

    /**
     * We can access the element from the front() and from the back() as well.
     */

    std::cout << "The first element from the front: " << list.front() << "\n";
    std::cout << "The first element from the end: " << list.back() << "\n";

    /**
     * We can change the value of the first and last element in the list.
     */

    list.front() = "Western Digital";
    list.back() = "SanDisk";

    std::cout << "-----New List are----- \n";
    for (std::string l: list) {
        std::cout << l << "\n";
    }

    /**
     * To add elements to a list, we can use push_front() and push_back().
     */
    list.push_back("IBM");
    list.push_front("Google");

    std::cout << "-----New List are------\n";
    for (std::string li: list) {
        std::cout << li << "\n";
    }

    /**
     * We can also remove the element from the begining and end using pop_front() and pop_back()
     */
    list.pop_back();
    list.pop_front();

    std::cout << "-----New List are------\n";
    for (std::string li: list) {
        std::cout << li << "\n";
    }

    return 0;
}
