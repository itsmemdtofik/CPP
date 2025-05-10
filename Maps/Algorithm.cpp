/**
 * !Algorithm in C++
 *
 * * Algorithms are used to solve problems by sorting, searching, and manipulating data structures.
 * Another important feature of iterators is that they are used with different algorithm functions, such as sort() and find() (found in the <algorithm> library), to sort and search for elements in a data structure.
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    std::cout << "Before Sorting : \n";
    for (auto &car : cars)
    {
        std::cout << car << "\n";
    }
    std::cout << "After Sorting : \n";
    std::sort(cars.begin(), cars.end());
    for (std::string &car : cars)
    {
        std::cout << car << "\n";
    }
    /**
     * By default, the elements are sorted in ascending order.
     * In the example above, the elements are sorted alphabetically since they are strings.
     * To reverse the order, you can use rbegin() and rend() instead of begin() and end():
     */

    std::vector<int> numbers = {1, 7, 3, 5, 9, 2};
    std::cout << "Before Sorting : \n";
    for (auto &num : numbers)
    {
        std::cout << num << "\n";
    }
    std::sort(numbers.begin(), numbers.end());
    std::cout << "After Sorting : \n";
    for (auto &num : numbers)
    {
        std::cout << num << "\n";
    }
    /**
     * If we had a vector of integers, they would be sorted numerically:
     * To reverse the order, you can use rbegin() and rend() instead of begin() and end():
     * for (auto num : ...)	    ✅ Yes	            ❌ No	Slower
     * for (auto &num : ...)	❌ No (reference)	✅ Yes	Faster
     */

    return 0;
}