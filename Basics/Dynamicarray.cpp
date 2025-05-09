/**
 * ! Dynamic array in C++
 *
 * For operations that require adding and removing array elements, C++ provides vector, which are resizable arrays.
 * The size of vector is dynamic it can grow and shrink as needed.
 * Vectors are found in the <vector> library, and they come with many usefull functions to add, remove and modify elements.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    vector<string> cars = {"volvo", "BMW", "Ford"};
    cars.push_back("Tesla");

    for (string car : cars)
    {
        cout << car << "\n";
    }
    return 0;
}
