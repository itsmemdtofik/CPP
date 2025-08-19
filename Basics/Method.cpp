/**
 * ! Class Methods in C++
 *
 * Method are functions that belong to class
 * There are two way to define the function that belongs to a class
 * 1. Inside Class definition
 * 2. Outside class definition
 *
 * 1.Inside Class definition: In the below example we define a function inside the class and we name it insideMethod()
 *
 * 2. Outside class definition: To define a function outside the class definition, you have to declare it inside the class and then define it outside of the class.
 */

#include <iostream>
#include <string>
using namespace std;

class insideClass
{
public:
    void insideMethod()
    {
        cout << "I am method that is declared and defined inside the class!\n";
    }
};

class outsideClass
{
public:
    void outsideMethod();
};

void outsideClass::outsideMethod()
{
    cout << "I am method that declared inside the class but defined outside of the class!\n";
}

int main()
{
    insideClass myObj;
    myObj.insideMethod();

    outsideClass outObj;
    outObj.outsideMethod();
    return 0;
}