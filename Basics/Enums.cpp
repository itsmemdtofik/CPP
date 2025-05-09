/**
 * !Enum in C++
 *
 * An enum is a special type that represents a group of constants(unchangable values).
 * To create an enum, use the enum keyword followed by the name of enum.
 * And sperate the enum items with a comma.
 * !Note: To access the enum, you must create a variable of it.
 * Inside the main() method, specify the enum keyword, followed by the name of the enum (Level) and then the name of the enum variable (var in this example):
 *
 * !Why And When To Use Enums?
 *
 * Enums are used to give names to constants, which makes the code easier to read and maintain.
 * Use enums when you have values that you know aren't going to change, like month days, days, colors, deck of cards, etc.
 */

#include <iostream>
#include <string>
using namespace std;

enum Level
{
    LOW = 25,
    MEDIUM,
    HIGH,
};

int main()
{
    enum Level var = HIGH;
    cout << var;
    return 0;
}
