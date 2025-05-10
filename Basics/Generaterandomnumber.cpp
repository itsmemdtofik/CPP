/**
 * ! Random Number
 * You can use the rand() function, found in the <cstdlib> library, to generate a random number:
 *
 */

#include <iostream>
#include <cstdlib>

int main()
{

    // Generate a random number between 0 and 100
    int randomNum = rand() % 101;

    std::cout << rand() << "\n";
    std::cout << randomNum;

    /**
     * Get a different rndom number each time the program runs
     */
    std::srand(time(0));

    /**
     * Generate a number between 0 and 100
     */
    int random_number = std::rand() % 101;
    std::cout << random_number << "\n";
    return 0;
}