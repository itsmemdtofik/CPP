/**
 * ! Multiple Inheritance in C++
 *
 * A class can also from more than one base class, using a comma-seperated list
 */

#include <iostream>
#include <string>

/*
 * Base class (parent)
 */

class BaseClass
{
public:
    void display()
    {
        std::cout << "I am from base class!" << std::endl;
    }
};

/*
 * Another Base class
 */

class AnotherBaseClass
{
public:
    void OtherDisplay()
    {
        std::cout << "I am from another base class!" << std::endl;
    }
};

/*
 * Derived class or child class
 */

class DerivedChildClass : public BaseClass, public AnotherBaseClass
{
};

int main()
{
    DerivedChildClass dObj;
    dObj.display();
    dObj.OtherDisplay();
    return 0;
}
