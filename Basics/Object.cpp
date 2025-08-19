/**
 * ! Creating an object in C++
 *
 * In C++, an object is created from a class. We have already created the class named MyClass, so now we can use this to create objects.
 * To create an object of MyClass, specify the class name, followed by the object name.
 * To access the class attributes (myNum and myString), use the dot syntax (.) on the object:
 */

#include <iostream>
#include <string>
using namespace std;

class MyClass
{
public:
    int myNum;
    string myString;
};

int main()
{

    MyClass myObj; // Create an object of MyClass

    myObj.myNum = 15;
    myObj.myString = "SanDisk";

    cout << "Number is : " << myObj.myNum << "\n";
    cout << "The name is : " << myObj.myString << "\n";
    return 0;
}