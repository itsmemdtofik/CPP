/**
 * ! Iterator in C++
 *
 * Iterators are used to access and iterate through elements of data structures (vectors, sets, etc.), by "pointing" to them.
 * It is called an "iterator" because "iterating" is the technical term for looping.
 * begin() and end() are functions that belong to data structures, such as vectors and lists
 * They do not belong to the iterator itself.
 */

#include <iostream>
#include <vector>
#include <string>

/*
 * Example Explained:
 *
 * 1. Create a vector of strings to store car manufacturers.
 *    std::vector<std::string> cars = {"Toyota", "BMW", "Ford"};
 *
 * 2. Declare a vector iterator 'it' for traversal.
 *    std::vector<std::string>::iterator it;
 *
 * 3. Loop through the vector using the iterator:
 *    - 'it' starts at the first element (cars.begin()).
 *    - Loop continues until 'it' reaches the end (cars.end()).
 *    - '++it' moves the iterator to the next element.
 *    - '*it' dereferences the iterator to access the current value.
 *
 * Example:
 * for (it = cars.begin(); it != cars.end(); ++it) {
 *     std::cout << *it << std::endl; // Prints each car brand
 * }
 */
int main()
{

    std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    /**
     * Now create a vector iterator called it.
     */

    std::vector<std::string>::iterator it;
    for (it = cars.begin(); it != cars.end(); it++)
    {
        std::cout << *it << "\n";
    }

    // it = cars.begin(); //First element in the vector
    // it = cars.begin() + 1; // second element in the vector
    // std::cout << *it << "\n";

    /**
     * end() points to one position after the last element in the vector (meaning it doesn't point to an actual element, but rather indicates that this is the end of the vector).
     * So, to use end() to point to the last element in the cars vector (Mazda), you can use cars.end() - 1:
     */

    it = cars.end() - 1;
    std::cout << "Last element in vector : " << *it << "\n";

    /**
     * We can also modify the value.
     */

    it = cars.begin();
    *it = "tesla";
    std::cout << *it << "\n";

    /**
     * However, when you need to add, modify, or remove elements during iteration, iterate in reverse, or skip elements, you should use iterators:
     */

    std::vector<std::string> cars1 = {"Volvo", "BMW", "Ford", "Mazda"};
    std::vector<std::string>::iterator newIt;
    for (auto newIt = cars1.begin(); newIt != cars1.end();)
    {
        if (*newIt == "BMW")
        {
            newIt = cars1.erase(newIt);
        }
        else
        {
            newIt++;
        }
    }

    std::cout << "After removing the BMW : " << "\n";
    for (const std::string &c : cars1)
    {
        std::cout << c << "\n";
    }

    /**
     * We can also iterate it in reverse mode.
     * For that we can use rbegin() and rend().
     */
    std::cout << "After removing the BMW and reading in reverse order : " << "\n";
    for (auto it = cars1.rbegin(); it != cars1.rend(); it++)
    {
        std::cout << *it << "\n";
    }
    return 0;
}
