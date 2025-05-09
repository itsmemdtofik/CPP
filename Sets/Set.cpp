/**
 * !Sets in C++
 *
 * * A set stores unique elements where they:
 *
 * Are sorted automatically in ascending order.
 * Are unique, meaning equal or duplicate values are ignored.
 * Can be added or removed, but the value of an existing element cannot be changed.
 * Cannot be accessed by index numbers, because the order is based on sorting and not indexing.
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
#include <set>

int main()
{

    std::set<std::string> set = {"apple", "Banana", "mango", "apple"};

    std::cout << "Printing the element of sets : " << "\n";
    for (std::string s : set)
    {
        std::cout << s << "\n";
    }

    std::set<int> setInt = {1, 7, 3, 2, 5, 9};

    std::cout << "Printing the element of sets : " << "\n";
    for (int s : setInt)
    {
        std::cout << s << "\n";
    }

    /**
     * Sort the set in Descending Order
     */
    std::set<int, std::greater<int>> setInt2 = {1, 7, 3, 2, 5, 9};
    std::cout << "Printing the element of sets : " << "\n";
    for (int s : setInt2)
    {
        std::cout << s << "\n";
    }

    /**
     * We cal also add the element using insert() function
     */
    set.insert("Tesla");
    set.insert("Toyoto");
    std::cout << "Printing the element of sets : " << "\n";
    for (std::string s : set)
    {
        std::cout << s << "\n";
    }

    /**
     * We cal also erase or remove the element using erase() function
     */
    set.erase("Tesla");
    set.erase("Toyoto");
    std::cout << "Printing the element of sets : " << "\n";
    for (std::string s : set)
    {
        std::cout << s << "\n";
    }
    return 0;
}