/**
 * ! Inheritance in C++ (A way to inherit attributes and methods from one class to another)
 *
 * In C++, it is possible to inherit attributes and methods from one class to another. We group the "inheritance concept" into two categories:
 * derived class (child) - the class that inherits from another class
 * base class (parent) - the class being inherited from
 *
 * Note: To inherit from a class use : symbol
 *
 * !Note: Why And When To Use "Inheritance"?
 * It is useful for code reusability: reuse attributes and methods of an existing class when you create a new class.
 */

#include <iostream>
#include <string>

/**
 * Base class
 */
class Vehicle
{
public:
    std::string brand = "Ford";
    void display()
    {
        std::cout << "I am displaying!" << "\n";
    }
};

/**
 * Derived class or child class
 */

class Car : public Vehicle
{
public:
    std::string model = "Mustang";
};

int main()
{

    Car car;
    car.display();

    std::cout << car.brand + " " + car.model << "\n";
    return 0;
}