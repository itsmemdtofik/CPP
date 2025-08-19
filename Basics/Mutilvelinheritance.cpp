/**
 * !Multilevel Inheritacne in C++
 *
 * A class can also be derived from one class, which is already derived from another class.
 * In the following example, MyGrandChild is derived from class MyChild(which is derived from MyClass)
 *
 */

#include <iostream>
#include <string>

/**
 * Base class (Parent)
 */

class MyClass
{
public:
    void display()
    {
        std::cout << "I am from parent class" << "\n";
    }
};

/**
 * Derived class (child)
 */

class MyChild : public MyClass
{
};

/**
 * Derived class (grandchild)
 */

class MyGrandChild : public MyChild
{
};

int main()
{

    MyGrandChild mgc;
    mgc.display();
    return 0;
}