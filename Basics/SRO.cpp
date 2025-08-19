/**
 * ! Scope Resolution Operator(SRO) in C++
 *
 * Common Use of this:
 *
 * 1. Access Global Variable When a Local Variable Has the Same Name
 * 2. Define a Class Function Outside the Class
 * 3. Access Namespaces
 * 4. Accessing Static Members of a Class
 * 5. Calling a Base Class Function in Derived Class (Inheritance)
 * 6. Enum Values Inside Class or Namespace
 * 7. Template Specialization or Definitions Outside Class
 *
 */

#include <iostream>
#include <string>

/**
 * !1. Access Global Variable When a Local Variable Has the Same Name
 *
 *  */

int x = 100; // global variable

void print()
{
    int x = 10;          // local variable
    cout << x << endl;   // prints 10 (local)
    cout << ::x << endl; // prints 100 (global)
}

/**
 * !2. Define a Class Function Outside the Class
 */
class MyClass
{
public:
    void show();
};

void MyClass::show()
{ // using scope resolution
    cout << "Hello!" << endl;
}
/**
 * ! Accessing static member of class
 */

class Test
{
public:
    static int count;
};

int Test::count = 0;

/**
 * !3. Access Namespaces
 */
namespace MyNamespace
{
    int value = 42;
}

/**
 * !5. Calling a Base Class Function in Derived Class (Inheritance)
 */

class Base
{
public:
    void print()
    {
        cout << "Base class" << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        Base::print(); // calling base class version
        cout << "Derived class" << endl;
    }
};

/**
 * !6. Enum Values Inside Class or Namespace
 */
class MyClass
{
public:
    enum Status
    {
        OK,
        ERROR
    };
};

MyClass::Status s = MyClass::OK;

/**
 * !7. Template Specialization or Definitions Outside Class
 */
template <typename T>
class MyTemplate
{
public:
    void func();
};

template <typename T>
void MyTemplate<T>::func()
{ // defining template function using ::
    cout << "Template func" << endl;
}

int main()
{
    cout << MyNamespace::value << endl; // prints 42
    Test::count = 5;
    cout << Test::count;
}