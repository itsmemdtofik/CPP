/**
 * ! Searching in C++
 * To search for specific elements in a vector, you can use the find() function.
 * It takes three parameters: start_iterator, end_iterator, value, where value is the value to search for:
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{

    std::vector<int> numbers = {1, 7, 3, 5, 9, 2};

    /**
     * Search for a number 3
     */

    auto it = find(numbers.begin(), numbers.end(), 3);

    /**
     * Check if the number 3 was found or not
     */
    if (it != numbers.end())
    {
        std::cout << "The number 3 was found!" << "\n";
    }
    else
    {
        std::cout << "The number 3 was not found." << "\n";
    }

    /**
     * Find the first value that is greater than 5 in the sorted vector
     * The upper_bound() function is typically used on sorted data structures. That's why we first sort the vector in the example above.
     */

    sort(numbers.begin(), numbers.end());
    auto it1 = std::upper_bound(numbers.begin(), numbers.end(), 5);

    std::cout << "The value which is greater than 3 is : " << *it1 << "\n";

    /**
     * We can also find the min_element() and max_element()
     * To find the smallest element in a vector, use the min_element() function:
     */

    auto it2 = std::max_element(numbers.begin(), numbers.end());
    std::cout << "The maximum element is : " << *it2 << "\n";

    int max_ele = 0;
    for (auto i : numbers)
    {
        max_ele = std::max(max_ele, i);
    }

    std::cout << "The maximum element is : " << max_ele << "\n";
    return 0;
}