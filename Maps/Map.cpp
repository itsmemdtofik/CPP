/**
 * ! Map in C++
 *
 * A map stores elements in "key/value" pairs.
 *
 * Elements in a map are:
 * Accessible by keys (not index), and each key is unique.
 * Automatically sorted in ascending order by their keys.
 * 
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
#include <map>

int main()
{

    std::map<std::string, int> people = {
        {"Jhon", 32},
        {"Adele", 45},
        {"Bo", 29}};

    std::cout << "Printing the element of map : " << "\n";
    for (auto person : people)
    {
        std::cout << person.first << " is: " << person.second << "\n";
    }

    return 0;
}