/**
 * ! Constructor in C++
 *
 * Constructor are used to initialize the object.
 * A constructor in C++ is a special method that it automatically called when an object of class is created.
 * To create a constructor, use the same name as the class, followed by parantheses ()
 *
 * !Note: Note: The constructor has the same name as the class, it is always public, and it does not have any return value.
 */

#include <iostream>
#include <string>
using namespace std;

class constructorClass
{
public:
    constructorClass()
    {
        cout << "I am creating a constructor class." << "\n";
    }
};

/**
 * Constructor parameter
 *
 */

class constructorParam
{
public:
    string name;
    string companyName;
    int age;
    constructorParam(string name, string companyName, int age)
    {
        this->name = name;
        this->companyName = companyName;
        this->age = age;
    }
};

/**
 * Just like functions, constructors can also be defined outside the class.
 */

class constructorOutsideClass
{
public:
    string name;
    string companyName;
    int age;
    constructorOutsideClass(string name, string companyName, int age);
};

constructorOutsideClass::constructorOutsideClass(string name, string companyName, int age)
{
    this->name = name;
    this->companyName = companyName;
    this->age = age;
}

int main()
{
    constructorClass ccObj;

    constructorParam cpObj("Tofik", "SanDisk", 26);

    constructorOutsideClass cpoObj("Kislay","Sandisk",28);

    cout << "Name is : " << cpObj.name << "\n";
    cout << "Company is: " << cpObj.companyName << "\n";
    cout << "Age : " << cpObj.age << "\n";

    cout << "Printing the values of constructur outside of class\n";
    cout << "Name is : " << cpoObj.name << "\n";
    cout << "Company is: " << cpoObj.companyName << "\n";
    cout << "Age : " << cpoObj.age << "\n";
    return 0;
}