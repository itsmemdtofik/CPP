/**
 * ! Vector in C++
 *
 * Both vectors and arrays are data structures used to store multiple elements of the same data type.
 * The difference is size of an array
 * Vector -> Dynamic in size
 * Array -> Static in size
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
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> cars = {
        "apple",
        "mango",
        "Banana",
        "Orange"};

    for (std::string car : cars)
    {
        std::cout << car << "\n";
    }

    std::cout << "The first element of vector is : " << cars[0] << "\n";

    /*
     * There are usefull function we can use : front(), back(), at(), push_back(), pop_back(), size(), empty().
     */

    std::cout << "The first element in vector using front() method : " << cars.front() << "\n";
    std::cout << "The last element of the vector using back() method : " << cars.back() << "\n";
    std::cout << "The element to find out at what position using at() method :" << cars.at(3) << "\n";

    cars.push_back("Tesla");

    for (std::string car : cars)
    {
        std::cout << car << "\n";
    }

    cars.pop_back();

    std::cout << "Deleting from the end of the vector using pop_back() method the vector is: " << "\n";
    for (std::string car : cars)
    {
        std::cout << car << "\t";
    }

    std::cout << "The size of the vector is : " << cars.size() << "\n";
    std::cout << "Is vector empty ? : " << cars.empty() << "\n";

    for (int i = 0; i < cars.size(); i++)
    {
        std::cout << cars[i] << "\n";
    }

    return 0;
}